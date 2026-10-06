#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

bool ordena(const float &a, const float &b){
    return a < b;
}

float calcularMedia(float v[], int &N){
    float soma = 0;
    for (int i=0;i<N;i++){
        soma += v[i];
    }
    return soma / N;
}

int main(){
    int N;
    cin >> N;
    float v[N];

    int dentro = 0;
    int infM = 0;
    int infG = 0;
    float media = 0;

    // Ler velocidades e classificar
    for(int i=0; i<N; i++){
        cin >> v[i];

        // Dentro do limite (até 80.0 km/h)
        if (v[i] <= 80.0){
            dentro++;
        }
        // Infração Média (80.0 a 100.0 km/h)
        else if (v[i] > 80.0 && v[i] <= 100.0){
            infM++;
        }
        // Infração Grave (acima de 100.0 km/h)
        else if (v[i] > 100.0){
            infG++;
        }
    }

    // Calcular Média
    media = calcularMedia(v,N);

    // Ordenar ordem crescente
    sort(v,v+N,ordena);

    // Exibir
    cout << fixed << setprecision(1);
    cout << endl;
    cout << "Veículos dentro do limite: " << dentro << endl
         << "Veículos com infração média: " << infM << endl
         << "Veículos com infração gravíssima " << infG << endl
         << "Menor velocidade: " << v[0] << endl
         << "Maior velocidade: " << v[N-1] << endl
         << "Velocidade média: " << media << endl;
    


    return 0;
}