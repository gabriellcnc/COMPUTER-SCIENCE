/* Boa prática:
Uso de constantes para definir o tamanho e manipular vetor
*/

#include <iostream>

using namespace std;

int main(){
    const int N = 5; // Boa prática: manter constante em caixa alta:
    int vet[N];

    cout << "Informe " << N << " valores: \n";
    for(int i=0; i<N; i++){
        cin >> vet[i];
    }

    cout << "Valores: \n";
    for(int i=0; i<N; i++){
        cout << vet[i] << ", ";
    }
    
    return 0;
}