#include <iostream>
#include <string>
#include <cmath>

using namespace std;



// string reverseString(string a);
void reverseString(string *a);
void swap(char *a, char *b);
// int reverseNumber(int a);
void reverseNumber(int *a);



int main(){

    return 0;
}

/* string is an object in c++ , passing by reference means you can access string[0][0]*/
void reverseString(string *a){
    for(int i = 0; i < a->length()/2/*== a[0].length()*/ ; i++){
        swap(a[0][i], a[0][a->length() - i - 1]);
    }
}

// string reverseString(string a){
//     for(int i = 0 ; i < a.length()/2 ; i++){
//         swap(a[i], a[a.length() - i - 1]);
//     }
//     return a;
// }

void swap(char *a, char *b){
    char c;
    c = *a;
    *a = *b;
    *b = c;
}



// 1234 -> 4000 + 300 + 20 + 1 = 4*10^3 + 3*10^2 + 2*10^1 + 1*10^0 = 4321
void reverseNumber(int *a){
    int b = 0;
    int i = to_string(*a).length() - 1; // length of the number - 1;
    while(*a > 0){
        b = b + pow(10,i) * (*a % 10);
        *a = *a/10;
        i--;
    }
    *a = b;
    cout << *a << endl;
}