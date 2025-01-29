#include "table.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOAD 0.75

static uint32_t hashString(const char *key, int length) {
  uint32_t hash = 2166136261u;

  for (int i = 0; i < length; i++) {
    hash ^= (uint8_t)key[i];
    hash *= 16777619;
  }
  return hash;
}

void initTable(Table *table) {
  table->capacity = 0;
  table->count = 0;
  table->entries = NULL;
}

static Entry *findEntry(Entry *entries, int capacity, char *key) {
  int index = hashString(key, strlen(key)) % capacity;

  for (;;) {

    Entry *entry = &entries[index];

    if (entry->key == NULL || strcmp(entry->key, key)) {
      return entry;
    }
    index = (index + 1) % capacity;
  }
}
bool tableset(Table *table, char *key, int value) {
  if (table->count + 1 > table->capacity * MAX_LOAD) {
    // need to grow array
    int capacity = GROWCAPACITY(table->capacity);
    /* adjustTable(); */
  }

  Entry *entry = findEntry(table->entries, table->capacity, key);

  return false;
}
