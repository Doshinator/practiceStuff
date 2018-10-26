#include <iostream>

using namespace std;

/*
    J = [0, 1, 2 , ... , 52] <- init the array to be 0, and set the 0 bit to 1 for the letter 
    if s in J[i] == 1, counter++
    return counter
*/

class Solution{
    private:
    int count = 0;
    int A[52] = {0};
    public:
        void initArray(string J);
        void printA();
        int jewls_stones(string J, string S);
        int getInt(void){return count;}
};



int main(){
    Solution *s1 = new Solution;
    string J = "abcZ";
    string S = "cbaz";

    s1->initArray(J);
    s1->printA();
    cout << s1->jewls_stones(J, S) << endl;
    return 0;
}
void Solution::printA(){
    for(int i = 0; i <= 52; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
void Solution::initArray(string J){
    
    for(int i = 0 ; i < J.size() ; i++){
        A[J[i] - 65] = 1;
    }
}
int Solution::jewls_stones(string J, string S){
    for(int i = 0; i < S.size(); i++){
        if(A[(S[i] - 65)]  == 1){
            count++;
        }
    }
    return count;
}