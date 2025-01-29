#ifndef table_h
#define table_h
#include <stdbool.h>

#define GROWCAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

typedef struct {
  char *key;
  int value;
} Entry;

typedef struct {
  int capacity;
  int count;
  Entry *entries;
} Table;

void initTable(Table *table);
bool tableset(Table *table, char *key, int value);
#endif
