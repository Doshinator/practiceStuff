#include "hash_table.h"
#include "prime.h"
#include <stdio.h>

int main(){

    
    ht_hash_table *ht = ht_new();

    ht_insert(ht, "a", "cat");
    printf("%s\n",(ht_search(ht, "a")));
    ht_del_hash_table(ht);

    return 0;
}