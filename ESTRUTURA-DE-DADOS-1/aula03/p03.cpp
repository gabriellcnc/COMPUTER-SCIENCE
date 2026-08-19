#include <iostream>
#include "funcoes.cpp"
using namespace std;

int main(){
    int n;
    cout << "N: ";
    cin >> n;
    int fat = fatorial(n);
    cout << "Fatorial de N: " << fat << endl;

    return 0;
}