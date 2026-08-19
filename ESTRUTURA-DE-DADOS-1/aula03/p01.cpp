#include <iostream>

using namespace std;

void adiciona(float &a, float &b){
    a = a + b;
    cout << "Na funcão adiciona: " << a << endl;
}

int main(){
    float x = 10, y = 0.5;
    adiciona(x,y);
    cout << "Na main: " << x << endl;

    return 0;
}