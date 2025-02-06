#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  Table table;
  initTable(&table);

  // add a key and value
  tableset(&table, "hello", 2);
  printTable(&table);
  tableset(&table, "erich", 1);
  printTable(&table);

  tableset(&table, "some", 2);
  printTable(&table);

  tableset(&table, "inkops", 9);
  printTable(&table);
  tableset(&table, "bsf", 01);
  printTable(&table);

  tableset(&table, "patna", 02);
  printTable(&table);

  tableset(&table, "merrut", 03);
  printTable(&table);

  tableset(&table, "noida", 04);
  printTable(&table);
  /* printf("%d", getTable(&table, "hello").value); */

  // get a value by a key
  // tableget(key);
}
