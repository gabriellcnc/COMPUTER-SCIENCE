// Define o tamanho do vetor de forma dinamica

#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Informe o tamanho do vetor:";
    cin >> n;
    string fornecedores[n];

    cout << "Digite o nome de " << n << " fornecedors \n";
    for(int i =0; i<n; i++){
        cin >> fornecedores[i];
    }

    cout << "Fornecedors: \n";
    for(int i =0; i<n; i++){
        cout << i << ": " << fornecedores[i] << endl;
    }

    return 0;
}