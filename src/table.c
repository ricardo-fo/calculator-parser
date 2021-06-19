#include <stdio.h>
#include "table.h"

const char * table[ROW][COL] = {
  { "+",   "-",   "*",   "/",   "sen", "cos", "exp", "num", "$",   "E'", "E",  "T",  "F"  },
  { NULL,  NULL,  NULL,  NULL,  NULL,  NULL,  NULL,  "s4",  NULL,  NULL, "1",  "2",  "3"  },
  { NULL,  NULL,  NULL,  NULL,  "s6",  "s7",  "s8",  "s4",  "ac",  NULL, "9",  "5",  "3"  },
  { NULL,  NULL,  NULL,  NULL,  "r3",  "r3",  "r3",  "s4",  "r3",  NULL, "9",  "2",  "10" },
  { "r6",  "r6",  NULL,  "r6",  "r6",  "r6",  "r6",  "r6",  NULL,  NULL, NULL, NULL, NULL },
  { "r10", "r10", "r10", "r10", "r10", "r10", "r10", "r10", "r10", NULL, NULL, NULL, NULL },
  { "s12", "s12", NULL,  "r3",  "r3",  "r3",  "r3",  "r3",  NULL, "9",  "2",  "10",  NULL },
  { NULL,  NULL,  "s13", NULL,  NULL,  NULL,  NULL,  NULL,  NULL, NULL,  NULL, NULL, NULL },
  { NULL,  NULL,  "s14", NULL,  NULL,  NULL,  NULL,  NULL,  NULL, NULL,  NULL, NULL, NULL },
  { NULL,  NULL,  "s15", NULL,  NULL,  NULL,  NULL,  NULL,  NULL, NULL,  NULL, NULL, NULL },
  { NULL,  NULL,  NULL,  NULL,  "s6",  "s7",  "s8",  "s4",  NULL, NULL,  "9",  "6",  "3"  },
  { "r6",  "r6",  "s16", "s17", "r6",  "r6",  "r6",  "r6",  "r6", NULL,  NULL, NULL, NULL },
  { NULL,  NULL,  NULL,  NULL,  "r1",  "r1",  "r1",  "r1",  "r1", NULL,  NULL, NULL, NULL },
  { NULL,  NULL,  NULL,  NULL,  "r2",  "r2",  "r2",  "r2",  "r2", NULL,  NULL, NULL, NULL },
  { "r7",  "r7",  "r7",  "r7",  "r7",  "r7",  "r7",  "r7",  "r7", NULL,  NULL, NULL, NULL },
  { "r8",  "r8",  "r8",  "r8",  "r8",  "r8",  "r8",  "r8",  "r8", NULL,  NULL, NULL, NULL },
  { "r9",  "r9",  "r9",  "r9",  "r9",  "r9",  "r9",  "r9",  "r9", NULL,  NULL, NULL, NULL },
  { "r4",  "r4",  NULL,  NULL,  "r4",  "r4",  "r4",  "r4",  "r4", NULL,  NULL, NULL, NULL },
  { "r5",  "r5",  NULL,  NULL,  "r5",  "r5",  "r5",  "r5",  "r5", NULL,  NULL, NULL, NULL },
};

// Cria uma nova célula
void show_table() {
  for (int j = 0; j < COL * 8 + 5; j++) {
    printf("-");
  }
  printf("\n");

  for(int i = 0; i < ROW; i++) {
    if (i > 0) {
      printf("|%2d ", i - 1);
    }

    for (int j = 0; j < COL; j++) {
      if (i == 0 && j == 0) {
        printf("|   |%5s  ", table[i][j] == NULL ? "" : table[i][j]);
      } else {
        printf("|%5s  ", table[i][j] == NULL ? "" : table[i][j]);
      }
    }
    printf("|\n");
    for (int j = 0; j < COL * 8 + 5; j++) {
      printf("-");
    }
    printf("\n");
  }
}
