#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
  bool areColumnsStored = false;

  FILE *pf;
  pf = fopen(filePath, "r");

  while (feof(pf) != true)
  {
    fgets(csvRow, MAX_CHAR_COUNT_PER_LINE, pf);

    printf("Row: %s\n", csvRow);

    if (!areColumnsStored)
    {
      char *token = strtok(csvRow, ",");

      for (int i = 0; token != NULL; i += 1)
      {
        int j = 0;
        while (token[j] != '\0')
        {
          tableColumns[i][j] = token[j];
          j += 1;
        }

        token = strtok(NULL, ",");
      }

      areColumnsStored = true;
    }
  }

  return 0;
}