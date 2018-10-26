#include <iostream>


int LCS(int i, int j, int X[], int Y[]);
int max(int a, int b);

int main(){

    int A[] = {1, 7, 9, 9, 9};
    int B[] = {7, 9};

    printf("length of the LCS : %d\n", LCS(5, 2, A, B));
    
   

    
    return 0;
}


/*
    Examine either one or two subproblems when finding an LCS of X = <x1, x2, ..., xm> and Y = < y1, y,..., yn>. 
    If xm = yn, we must find an LCS of Xm-1 and Yn-1. Appending xm = yn to this LCS yields
    an LCS of X and Y . 
    If xm =/= yn, then we must solve two subproblems: finding an
    LCS of Xm-1 and Y and finding an LCS of X and Yn-1. Whichever of these two
    LCSs is longer is an LCS of X and Y.
*/



/*  if memo[i, j] =/= null
        v = memo[i.j]
    else if i or j == 0
        v = 0;
    else if X[i] == Y[j]
        v = LCS(i - 1, j - 1, X, Y)
    else 
        v = max{LCS(i-1, j, X, Y), LCS(i, j-1, X, Y)}
    memo[i,j] = v
    return v
*/


int LCS(int i, int j, int X[], int Y[]){
    int memo[i][j];
    int v;
    for(int k = 0; k < i; k++){
        for(int l = 0; l < j; l++){
            memo[k][l] = -1;
        }
    }

    
    if (memo[i - 1][j - 1] != -1)
        v = memo[i - 1][j - 1];
    else if(i == 0 || j == 0){
        return 0;
    }
    else if(X[i - 1] == Y[j - 1]){
        //printf("%d %d", X[i - 1], Y[j - 1]);
        v = LCS(i - 1, j - 1, X, Y) + 1;
    }
    else
        v = max(LCS(i - 1, j, X, Y), LCS(i, j - 1, X, Y));
    memo[i][j] = v;
    return v;
}

int max(int a, int b){
    return (a > b) ? a : b;
    //if a > b, return a, ow b;
}




