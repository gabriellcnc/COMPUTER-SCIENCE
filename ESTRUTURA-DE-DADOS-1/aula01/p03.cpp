#include <iostream>

#include <iomanip> 

using namespace std;

int main(){

    float a,b;
    cout << "Insira 2 numeros para uma divisão: " << endl;
    cin >> a >> b;

    cout << "O resultado é: " << fixed << setprecision(2) << a/b << endl;

    return 0;
}