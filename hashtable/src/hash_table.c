#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_table.h"


static ht_item HT_DELETED_ITEM = {NULL, NULL};

static const int HT_PRIME_1 = 151;
static const int HT_PRIME_2 = 163;


static ht_item* ht_new_item(const char* k, const char* v){
    // allocates a chunk of memory the size of an ht_item
    // and saves a copy of the strings k and v in the new chunk of memory.
    ht_item *i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

ht_hash_table* ht_new(){
    /*
        ht_new()
        malloc a new hash table.
        size = 53 
        initialise the array of items with calloc
    */
    ht_hash_table *i = malloc(sizeof(ht_hash_table));
    i->size = 53;
    i->count = 0;
    i->items = calloc((size_t)i->size, sizeof(ht_item*));
    return i;
}

static void ht_del_item(ht_item* i){
    free(i->key);
    free(i->value);
    free(i);
}

void ht_del_hash_table(ht_hash_table* ht){
    for(int i = 0; i < ht->size ; i++){
        ht_item *item = ht->items[i];
        if(item != NULL){
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}

static int ht_hash(const char *string, const int k, const int m){
    // h(k) = k^strlen - i + i % m
    long hash = 0;
    const int string_len = strlen(string);
    for(int i = 0; i < string_len; i++){
        hash += (long)pow(k, string_len - (i+1)) * string[i];
        hash = hash % m;
    }
    return (int)hash;
}


 
static int ht_get_hash(const char* string, const int m, const int attempt){
    //h(k, i) = (h(k) + i * h(k) + 1) % m
    const int hash_1 = ht_hash(string, HT_PRIME_1, m);
    const int hash_2 = ht_hash(string, HT_PRIME_2, m);
    return (hash_1 + (attempt * (hash_2 + 1))) % m;
}

void ht_insert(ht_hash_table* ht, const char* key, const char* value){
    // iterate through indexes until we find an empty bucket
    // insert the item into that bucket + increment the hash table's count 
    ht_item *item = ht_new_item(key, value);
    int index = ht_get_hash(item->key, ht->size, 0);
    // put into the arry
    ht_item *curr_item = ht->items[index];
    int i = 1;
    while(curr_item != NULL){
        if (curr_item != &HT_DELETED_ITEM) {
            if (strcmp(curr_item->key, key) == 0) {
                ht_del_item(curr_item);
                ht->items[index] = item;
                return;
            }
        }
        index = ht_get_hash(item->key, ht->size, i);
        curr_item = ht->items[index];
        i++;
    }
    ht->items[index] = item;
    ht->count++;
}

//given the key, search for a value related to that key
char* ht_search(ht_hash_table* ht, const char* key){
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while(item != NULL){
        if (item != &HT_DELETED_ITEM) { 
            if(strcmp(item->key, key) == 0){
                return item->value;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    return NULL;
}

void ht_delete(ht_hash_table* ht, const char* key){
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while(item != NULL){
        if(item != &HT_DELETED_ITEM){
            if(strcmp(item->key, key) == 0){
                ht_del_item(item);
                ht->items[index] = &HT_DELETED_ITEM;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    ht->count--;
}