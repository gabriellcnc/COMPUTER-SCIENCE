// Define os valores no momento da declaração do vetor.

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    float vet[]{1.321, 3.123, 1.999, 5.045, 0.333};
    //TO DO: Somar todos os valores desse vetor

    float soma = 0;
    float somat =0;
    int qtd = 0;
    cout << "\n \n";
    for(int i=0; i<5; i++){
        somat += vet[i];
        cout << soma << " + " << vet[i] << " = " << somat << endl;
        soma += vet[i];
        qtd++;
    }
    cout << "\nQuantidade de somas: " << qtd << endl;
    cout << "----------------------- \n";
    cout << "Soma total: " << fixed << setprecision(2) << somat << endl << endl;


    return 0;
}