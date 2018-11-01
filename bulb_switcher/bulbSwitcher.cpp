#include <iostream>
#include <cmath>


using namespace std;
int bulbSwitcher(int n);

int main(){

    cout << "There are " << bulbSwitcher(20) << " bulbs on"<< endl;


    return 0;
}

int bulbSwitcher(int n){

    return sqrt(n);
}