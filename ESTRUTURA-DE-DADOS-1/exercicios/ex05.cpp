/*
Problema: A Corrida de Lesmas

Para cada grupo de lesmas, leia:
- L: quantidade de lesmas
- L velocidades

O objetivo é descobrir a maior velocidade do grupo
e informar o nível da lesma mais rápida.

Classificação:

Nível 1:
velocidade menor que 10

Nível 2:
velocidade maior ou igual a 10 e menor que 20

Nível 3:
velocidade maior ou igual a 20

Existem vários casos de teste e a entrada termina em EOF.
*/

#include <iostream>

using namespace std;

int main() {

    int L;

    // Continua enquanto houver casos de teste
    while (cin >> L) {

        int velocidade;
        int maior = 0;

        // Lê as velocidades
        for (int i = 0; i < L; i++) {
            cin >> velocidade;

            // Guarda a maior velocidade
            if (velocidade > maior) {
                maior = velocidade;
            }
        }

        // Classifica a maior velocidade
        if (maior < 10) {
            cout << 1 << endl;
        }
        else if (maior < 20) {
            cout << 2 << endl;
        }
        else {
            cout << 3 << endl;
        }
    }

    return 0;
}