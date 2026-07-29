// Exemplo de operador ternário

#include <iostream>

using namespace std;

int main(){
    double a,b;
    cout << "Informe dois valores: \n";
    cin >> a >>b;

    // condição ? valor se TRUE : valor se FALSE
    double maior = (a > b ? a : b);
    cout << "Maior: " << maior;

    return 0;
}