#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

bool isBadVersion(int n);
int firstBadVersion(int n);


int main(){
    cout << "The first bad version is : "<< firstBadVersion(10) << endl;
    return 0;
}

// bool isBadVersion(int n){
//     srand (time(NULL));
//     int theBadVersion = rand() % 10 + 1 ;
//     //cout << "the bad version is : " << theBadVersion << endl;
//     if(n != theBadVersion){
//         //cout << "call isBadVersion(" << n << ") -> false" << endl;
//         return false;
//     }
//     //cout << "call isBadVersion(" << n << ") -> true" << endl;
//     return true;
//     return true;
// }

int firstBadVersion(int n){
    int start = 1;
    int end = n;

    /*
        Case: Mid, bad version -> false, therefore everything before mid must be good,
        so we search [mid+1 ..end]

        Case: Mid, bad version ->true, mid may or may not be the final bad version,
        so you still have to search from [start ..mid]
        if(isBadVersion(mid)){
    }   
    */

    while(start < end){
        int mid = start + (end - start) / 2 ;
        if(isBadVersion(mid)){  // isBadVersion(int) -> function does not work. therefore ths program will not compile but this is the correct implementation
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    return start;
}