#include "table.h"
#include <stdint.h>
#include <stdio.h>
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

    if (entry->key == NULL || strcmp(entry->key, key) == 0) {

      return entry;
    }
    index = (index + 1) % capacity;
  }
}

Entry getTable(Table *table, char *key) {

  return *findEntry(table->entries, table->capacity, key);
}

void printTable(Table *table) {

  printf("INDEX - |KEY\tVALUE|\n");
  for (int i = 0; i <= table->capacity; i++) {
    Entry entry = table->entries[i];

    printf("%d - |%s\t%d|\n", i, entry.key, entry.value);
  }
}

static void adjustTable(Table *table, int capacity) {
  printf("======TABLE ADJUST======\n\n");
  Entry *old = table->entries;
  Entry *new = malloc(capacity * sizeof(Entry));
  table->entries = new;

  for (int i = 0; i < table->capacity; i++) {

    Entry entry = old[i];

    if (entry.key == NULL)
      continue;

    for (;;) {

      int index = hashString(entry.key, strlen(entry.key)) % capacity;

      if (table->entries[index].key == NULL ||
          strcmp(table->entries[index].key, entry.key) == 0) {

        new[index].key = entry.key;
        new[index].value = entry.value;
        break;
      }
      index = (index + 1) % capacity;
    }
  }

  table->capacity = capacity;
}

bool tableset(Table *table, char *key, int value) {
  if (table->count + 1 > table->capacity * MAX_LOAD) {
    // need to grow array
    int capacity = GROWCAPACITY(table->capacity);
    adjustTable(table, capacity);
  }

  Entry *entry = findEntry(table->entries, table->capacity, key);
  bool isKey = entry->key == NULL;

  if (isKey) {
    table->count++;
  }

  entry->key = key;
  entry->value = value;

  return false;
}
