#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CHAR_COUNT_PER_LINE 100
#define MAX_COLUMNS 50

char *promptTableName()
{
  char *tableName = (char *)malloc(100 * sizeof(char));

  printf("Write your table name: ");

  scanf("%s", tableName);

  return tableName;
}

char *getFilePath(int argc, char *argv[])
{
  if (argc <= 1)
  {
    printf("File path is missing.\n");

    return NULL;
  }

  return argv[1];
}

int main(int argc, char *argv[])
{

  char csvRow[MAX_CHAR_COUNT_PER_LINE];
  const char *filePath = getFilePath(argc, argv);
  char *tableName = promptTableName();

  if (!filePath)
    return 1;

  FILE *
      pf;
  pf = fopen(filePath, "r");

  char columns[10000];
  fgets(columns, MAX_CHAR_COUNT_PER_LINE, pf);

  while (feof(pf) != true)
  {
    fgets(csvRow, MAX_CHAR_COUNT_PER_LINE, pf);

    printf("INSERT INTO %s (%s) VALUES (%s);\n", tableName, columns, csvRow);
  }

  free(tableName);

  return 0;
}
