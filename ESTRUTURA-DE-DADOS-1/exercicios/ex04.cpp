/*
Problema: Quadro de Medalhas

Leia N países com:
- nome
- quantidade de medalhas de ouro
- quantidade de medalhas de prata
- quantidade de medalhas de bronze

Ordene os países seguindo estes critérios:

1º - Maior número de medalhas de ouro
2º - Em caso de empate, maior número de medalhas de prata
3º - Em caso de empate, maior número de medalhas de bronze
4º - Se continuar empatado, ordenar pelo nome em ordem alfabética

Depois, exiba os países já ordenados.
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct pais {
    string nome;
    int ouro;
    int prata;
    int bronze;
};

bool compara(const pais &p1, const pais &p2) {

    return p1.ouro > p2.ouro ||

           (p1.ouro == p2.ouro &&
            p1.prata > p2.prata) ||

           (p1.ouro == p2.ouro &&
            p1.prata == p2.prata &&
            p1.bronze > p2.bronze) ||

           (p1.ouro == p2.ouro &&
            p1.prata == p2.prata &&
            p1.bronze == p2.bronze &&
            p1.nome < p2.nome);
}

int main() {

    int N;
    cin >> N;

    pais paises[500];

    // Lê os dados dos países
    for (int i = 0; i < N; i++) {
        cin >> paises[i].nome
            >> paises[i].ouro
            >> paises[i].prata
            >> paises[i].bronze;
    }

    // Ordena os países
    sort(paises, paises + N, compara);

    // Exibe os países ordenados
    for (int i = 0; i < N; i++) {
        cout << paises[i].nome << " "
             << paises[i].ouro << " "
             << paises[i].prata << " "
             << paises[i].bronze << endl;
    }

    return 0;
}