#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

typedef struct {
    int id;
    int value;
    UT_hash_handle hh; // Gestionnaire de hachage
} Entry;

Entry* users = NULL;

void add_user(int id, int value) {
    Entry* user = (Entry*)malloc(sizeof(Entry));
    user->id = id;
    user->value = value;
    HASH_ADD_INT(users, id, user);
}

Entry* find_user(int id) {
    Entry* user;
    HASH_FIND_INT(users, &id, user);
    return user;
}

void delete_user(Entry* user) {
    HASH_DEL(users, user);
    free(user);
}

void free_all() {
    Entry* current_user, *tmp;
    HASH_ITER(hh, users, current_user, tmp) {
        HASH_DEL(users, current_user);
        free(current_user);
    }
}

int main() {
    add_user(1, 10);
    add_user(2, 20);
    Entry* user = find_user(1);
    if (user) {
        printf("User ID 1, Value: %d\n", user->value);
    }
    free_all();
    return 0;
}
