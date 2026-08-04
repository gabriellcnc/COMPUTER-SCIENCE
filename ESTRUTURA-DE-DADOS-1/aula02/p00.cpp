// Exemplo de array unidimensional

#include <iostream>

using namespace std;

int main(){
    int vet[6]; // Criando um vetor, alocando um espaço de 6 inteiros na memoria
    cout << "Informe 6 valores; \n";
    for(int i=0; i<6; i++){
        cin >> vet[i];
    }

    cout << "Valores: \n";
    for(int i=0; i<6; i++){
        cout << vet[i] << ", " << endl;
    }
    
    cout << "Ordem inversa: \n";
    for(int i=5; i>=0; i--){
        cout << vet[i] << ", " << endl;
    }

    cout << "Valores + Indices: \n";
    for(int i=0; i<6; i++){
        cout << "Vet[" << i << "] = " << vet[i] << endl;
    }

    return 0;
}