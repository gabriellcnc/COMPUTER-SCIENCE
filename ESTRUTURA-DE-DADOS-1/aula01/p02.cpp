// Exemplo de entrada e saída de dados

#include <iostream>

using namespace std; 

int main(){

    string nome;

    cout << "Informe seu nome: ";
    //cin >> nome;       // Lê até o espaço em branco.
    getline(cin, nome);  // Lê toda a linha.

    cout << "Meu nome é: " << nome << endl;

    return 0;
}