#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  Table table;
  initTable(&table);

  // add a key and value
  tableset(&table, "hello", 2);

  // get a value by a key
  // tableget(key);
}
