//STACK OVERFLOW

#include <iostream>

using namespace std;

//função recursiva
void foo(int n){
    double d;
    //static double d;
    cout << n << " " << &d << endl;
    foo(n+1);
}

int main(){
    foo(0);

    return 0;
}