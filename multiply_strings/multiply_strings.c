#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {false, true} bool;

char *multiply(char *num1, char *num2);
int strSize(char *a);

int main(){

    // printf("%s\n", multiply("400", "10"));
    return 0;
}


/**
 *  ASCII
 * 
 *  CH INT
 *  0   48
 *  1   49
 *  2   50
 *  3   51
 *  4   52
 *  5   53  
 *  6   54
 *  7   55
 *  8   56
 *  9   57
 * 
 * */ 

int strSize(char *a){
    int length = 0;
    while(a[length] != '\0'){
        length++;
    }
    return length;
}

char *multiply(char *num1, char *num2){
    int num1Size = strSize(num1);
    int num2Size = strSize(num2);
    printf("size1 : %d, size2 : %d\n", num1Size, num2Size);
    int i = 0;
   

    char *multiple = (char*)malloc(sizeof(char) * (num1Size + num2Size + 1));
    
    /**
     * Init Array
    */
    for(i = 0; i < (num1Size+num2Size); i++){
        multiple[i] = '0';
    }
    /**
     * Print Array
    */
    // for(i = 0; i < (num1Size+num2Size); i++){
    //     printf("%c" , multiple[i]);
    // }

    int j = num1Size;
    int k = num2Size;
    /**
     * 
     */
    for(j = num1Size ; j > 0; j--){
        for(k = num2Size; k > 0 ; k--){
            multiple[j + k - 1] += (num1[j - 1] - 48) * (num2[k - 1] - 48);
        }
    }

    return multiple;
}
