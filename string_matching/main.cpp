#include "stringMatching.h"

int main(){
    string t[] = {"a","a","d","b","a","d","b"};
    string p[] = {"a", "d", "b"};
    NAIVE_STRING_MATCH(t, p);
    return 0;
}