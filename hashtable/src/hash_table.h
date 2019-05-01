#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_


typedef struct{
    char *key;
    char *value;
}ht_item;

typedef struct{
    int size;
    int count;
    ht_item **items;
}ht_hash_table;


static ht_item* ht_new_item(const char* k, const char* v);

ht_hash_table* ht_new();

//deleting ht_items
static void ht_del_item(ht_item* i);

//deleteing ht_hash_tables
void ht_del_hash_table(ht_hash_table* ht);



//hashing function
static int ht_hash(const char *string, const int k, const int m); /* - static, meaining it can only be used in the file scope it is delcared in  */

/*
The hash function we choose should:

*   Take a string as its input and return a number between 0 and m, our desired bucket array length.
*   Return an even distribution of bucket indexes for an average set of inputs. If our hash function is unevenly distributed, it will put more items in some      buckets than others. This will lead to a higher rate of collisions. Collisions reduce the efficiency of our hash table.
    h(k) = ( k^(str_len - (i + 1)) * s[i] ) % (m)

*/

//solving for collison (double hashing)
static int ht_get_hash(const char* string, const int m, const int attempt);



void ht_insert(ht_hash_table* ht, const char* key, const char* value);
char* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* ht, const char* key);

#endif  // HASH_TABLE_H_

