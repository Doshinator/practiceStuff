#include "stringMatching.h"
// runtime is O((n-m + 1) m)
void NAIVE_STRING_MATCH(string T[], string P[]){
    int n = 7; // n = T.length
    int m = 3; // m = P.length

    // loop through the text pattern
    for(int s = 0 ; s <= (n - m) ; s++){
        int j;
        // loop through the Pattern length
        // checking if P[1 ..m] = T[1 ..i + s]
        for(j = 0; j < m ; j++){
            if(P[j] != T[j + s]){
                break;
            }
        }
        if(j == m){
            cout << "Pattern occured at index : " << s << endl;
        }
    }
}


void RABIN_KARP(string T[], string P[]){
    
}

