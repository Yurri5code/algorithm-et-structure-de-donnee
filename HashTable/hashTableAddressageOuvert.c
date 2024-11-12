#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
    int occupied;
} Entry;

typedef struct {
    Entry table[TABLE_SIZE];
} HashTable;

int hash(int key) {
    return key % TABLE_SIZE;
}

HashTable* createTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->table[i].occupied = 0;
    }
    return table;
}

void insert(HashTable* table, int key, int value) {
    int index = hash(key);
    while (table->table[index].occupied) {
        index = (index + 1) % TABLE_SIZE;
    }
    table->table[index].key = key;
    table->table[index].value = value;
    table->table[index].occupied = 1;
}

int search(HashTable* table, int key) {
    int index = hash(key);
    int startIndex = index;
    while (table->table[index].occupied) {
        if (table->table[index].key == key) {
            return table->table[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) return -1; // Tour complet
    }
    return -1; // Non trouvé
}

void delete(HashTable* table, int key) {
    int index = hash(key);
    int startIndex = index;
    while (table->table[index].occupied) {
        if (table->table[index].key == key) {
            table->table[index].occupied = 0;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) return; // Tour complet
    }
}

void freeTable(HashTable* table) {
    free(table);
}
