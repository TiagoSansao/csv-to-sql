#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CHAR_COUNT_PER_LINE 100
#define MAX_COLUMNS 50

int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    printf("File path is missing.\n");

    return 1;
  }

  const char *filePath = argv[1];
  char csvRow[MAX_CHAR_COUNT_PER_LINE];
  char tableColumns[MAX_COLUMNS][MAX_CHAR_COUNT_PER_LINE];
  char columns[10000];
  char tableName[100];
  bool areColumnsStored = false;

  printf("Write your table name: ");
  scanf("%s", tableName);

  FILE *pf;
  pf = fopen(filePath, "r");

  fgets(csvRow, MAX_CHAR_COUNT_PER_LINE, pf);
  strcpy(columns, csvRow);

  while (feof(pf) != true)
  {
    fgets(csvRow, MAX_CHAR_COUNT_PER_LINE, pf);

    printf("INSERT INTO %s (%s) VALUES (%s)\n", tableName, columns, csvRow);
  }

  return 0;
}