#include <stdlib.h>

typedef struct bucket {
char *key;
void *value;
struct bucket *next;
} Bucket;

struct hashtable {
Bucket **buckets;
int num_buckets;
};

Hashtable *hashtable_create(int num_buckets) {
Hashtable *table = malloc(sizeof(Hashtable));
table->buckets = malloc(sizeof(Bucket ) num_buckets);
table->num_buckets = num_buckets;
return table;
}

void hashtable_insert(Hashtable table, char *key, void value) {
int index = hash_function(key) % table->num_buckets;
Bucket *new_bucket = malloc(sizeof(Bucket));
new_bucket->key = key;
new_bucket->value = value;
new_bucket->next = table->buckets[index];
table->buckets[index] = new_bucket;
}

void hashtable_get(Hashtable *table, char key) {
int index = hash_function(key) % table->num_buckets;
Bucket *bucket = table->buckets[index];
while (bucket != NULL) {
if (strcmp(bucket->key, key) == 0) {
return bucket->value;
}
bucket = bucket->next;
}
return NULL;
}

void hashtable_delete(Hashtable *table) {
for (int i = 0; i < table->num_buckets; i++) {
Bucket *bucket = table->buckets[i];
while (bucket != NULL) {
Bucket *next = bucket->next;
free(bucket->key);
free(bucket);
bucket = next;
}
}
free(table->buckets);
free(table);
}
