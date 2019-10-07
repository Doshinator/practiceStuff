#include "hash_table.h"
#include "prime.h"
#include <stdio.h>


#define ROW 5
#define COL 7
int main(){
    
    ht_hash_table *ht = ht_new();

    ht_insert(ht, "a", "cat");
    ht_insert(ht, "b", "dog");
    printf("%s\n",(ht_search(ht, "a")));
    printf("%s\n",(ht_search(ht, "b")));
    ht_del_hash_table(ht);


    return 0;
}