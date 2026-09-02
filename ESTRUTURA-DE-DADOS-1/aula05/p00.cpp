// Primeiro exemplo de sort

#include <iostream>
#include <algorithm> // Nescessario para usar o std::sort

using namespace std;

int main(){

    int numeros[10]={42,15,17,95,06,10,21,16,10,98};

    cout << "Vetor original: ";
    for(int i = 0; i<10; i++){
        cout << numeros[i] << " ";
    }
    cout << endl << endl;

    // Ordenar usando a função std::sort

    sort(numeros,numeros+10);

    cout << "Vetor ordenado: ";
    for(int i = 0; i<10; i++){
        cout << numeros[i] << " ";
    }
    cout << endl << endl;

    // Or

    return 0;
}