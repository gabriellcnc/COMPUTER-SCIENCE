/*
Enunciado: Desempenho de Atletas nos 100 Metros Rasos

Um técnico de atletismo deseja desenvolver um sistema para classificar
e analisar o desempenho de seus atletas na corrida de 100 metros rasos.

O programa deve ler um número N representando a quantidade de atletas.
Para cada atleta, deve ser lido o seu tempo em segundos.

O programa deve:

- Contar os desempenhos "Excelentes":
  tempo < 11.00 segundos

- Contar os desempenhos "Bons":
  11.00 <= tempo < 12.00 segundos

- Contar os desempenhos que "Precisam Melhorar":
  tempo >= 12.00 segundos

- Exibir, com duas casas decimais:
  * Melhor tempo
  * Pior tempo
  * Tempo médio

- Exibir os tempos em ordem decrescente.

OBS:
Além da função main, o programa deve possuir pelo menos uma outra
função que receba parâmetro e retorne um valor.

Exemplo de Entrada:

6
10.85
11.50
12.30
9.95
11.20
13.45

Exemplo de Saída:

Excelente: 2 atletas
Bom: 2 atletas
Precisa Melhorar: 2 atletas

Melhor tempo: 9.95s
Pior tempo: 13.45s
Tempo médio: 11.54s

Tempos em ordem decrescente:
13.45, 12.30, 11.50, 11.20, 10.85, 9.95
*/

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Calcula e retorna a média dos tempos
float calcularMedia(float vetor[], int tamanho) {
    float soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma = soma + vetor[i];
    }

    return soma / tamanho;
}

int main() {

    int N;

    cin >> N;

    float tempo[N];

    int excelentes = 0;
    int bons = 0;
    int melhorar = 0;

    // Lê os tempos e classifica os atletas
    for (int i = 0; i < N; i++) {

        cin >> tempo[i];

        if (tempo[i] < 11) {
            excelentes++;
        }
        else if (tempo[i] >= 11 && tempo[i] < 12) {
            bons++;
        }
        else {
            melhorar++;
        }
    }

    // Começa usando o primeiro tempo como melhor e pior
    float melhor = tempo[0];
    float pior = tempo[0];

    // Procura o melhor e o pior tempo
    for (int i = 1; i < N; i++) {

        if (tempo[i] < melhor) {
            melhor = tempo[i];
        }

        if (tempo[i] > pior) {
            pior = tempo[i];
        }
    }

    // Calcula a média usando a função
    float media = calcularMedia(tempo, N);

    // Ordena os tempos do maior para o menor
    sort(tempo, tempo + N, greater<float>());

    // Exibe valores com duas casas decimais
    cout << fixed << setprecision(2);

    cout << "Excelente: " << excelentes << " atletas" << endl;
    cout << "Bom: " << bons << " atletas" << endl;
    cout << "Precisa Melhorar: " << melhorar << " atletas" << endl;

    cout << endl;

    cout << "Melhor tempo: " << melhor << "s" << endl;
    cout << "Pior tempo: " << pior << "s" << endl;
    cout << "Tempo medio: " << media << "s" << endl;

    cout << endl;

    cout << "Tempos em ordem decrescente: ";

    // Mostra os tempos ordenados
    for (int i = 0; i < N; i++) {

        cout << tempo[i];

        if (i < N - 1) {
            cout << ", ";
        }
    }

    cout << endl;

    return 0;
}