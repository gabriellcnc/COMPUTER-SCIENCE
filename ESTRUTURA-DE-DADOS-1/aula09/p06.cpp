#include <iostream>

using namespace std;

void foo(){
    int n=0; //Alocação automática
    n++;
    cout <<&n << " " << n << endl;
}

int main(){
    foo();
    foo();
    foo();
    return 0;
}