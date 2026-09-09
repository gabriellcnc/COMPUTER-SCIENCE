#include <iostream>
#include <iomanip>   // setprecision
#include <algorithm> // std::sort
using namespace std; 

float calcularMedia(float vetor[], int tamanho){
    float soma = 0;

    for(int i = 0; i < tamanho; i++){
        soma = soma + vetor[i];
    }

    return soma / tamanho;
}

int main(){
    int N;

    cout << "Digite o numero de atletas: ";
    cin >> N;

    float tempo[N];

    int excelentes = 0;
    int bons = 0;
    int melhorar = 0;

    int i;

    for(i = 0; i < N; i++){
        cout << "Digite o tempo do atleta " << i + 1 << ": ";
        cin >> tempo[i];

        if(tempo[i] < 11){
            excelentes = excelentes + 1;
        }
        else if(tempo[i] >= 11 && tempo[i] < 12){
            bons = bons + 1;
        }
        else{
            melhorar = melhorar + 1;
        }
    }

    float melhor = tempo[0];
    float pior = tempo[0];

    for(i = 1; i < N; i++){
        if(tempo[i] < melhor){
            melhor = tempo[i];
        }

        if(tempo[i] > pior){
            pior = tempo[i];
        }
    }

    float media = calcularMedia(tempo, N);

    sort(tempo, tempo + N, greater<float>());

    cout << fixed << setprecision(2);

    cout << "\n--- RESULTADOS ---\n";
    cout << "Excelentes: " << excelentes << endl;
    cout << "Bons: " << bons << endl;
    cout << "Precisam melhorar: " << melhorar << endl;

    cout << "Melhor tempo: " << melhor << " segundos" << endl;
    cout << "Pior tempo: " << pior << " segundos" << endl;
    cout << "Tempo medio: " << media << " segundos" << endl;

    cout << "\nTempos em ordem decrescente:\n";

    for(i = 0; i < N; i++){
        cout << tempo[i] << " ";
    }

    cout << endl;

    return 0;
}