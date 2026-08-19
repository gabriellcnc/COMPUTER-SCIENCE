#include <iostream>

using namespace std;

void dobrar( int v[], int tamanho){  // Como estamos mudando o vetor de referência, aleta o original
    for(int i=0; i<tamanho; i++){
        v[i] = v[i] * 2;
    }
}
int main(){
    int vet[3]{1,2,3};         
    dobrar(vet,3);              // Vetores o envio é sempre por referência
    for(int i=0; i<3; i++){
        cout << vet[i] << " ";
    }
    cout << " \n";

    return 0;
}