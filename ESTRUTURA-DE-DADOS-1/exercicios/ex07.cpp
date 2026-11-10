
/*
O professor Rolien organizou junto às suas turmas de Ciência da Computação
a confecção de camisetas para que fossem ao mesmo tempo bonitas e baratas.

Os alunos podem escolher entre duas cores e três tamanhos:
P, M ou G.

O objetivo é organizar as camisetas pela cor, tamanho e nome.

Entrada:
A entrada contém vários casos de teste.
Cada caso começa com um valor N (1 <= N <= 60),
indicando a quantidade de camisetas.

Para cada camiseta são informados:
- Nome completo do estudante;
- Cor da camiseta (branco ou vermelho);
- Tamanho (P, M ou G).

A entrada termina quando N for igual a zero (0).

Saída:
Imprimir as camisetas ordenadas:
1. Cor em ordem crescente;
2. Tamanho em ordem decrescente;
3. Nome em ordem alfabética crescente.

Deve existir uma linha em branco entre dois casos de teste.

Exemplo de Entrada:

9
Maria Jose
branco P
Mangojata Mancuda
vermelho P
Cezar Torres Mo
branco P
Baka Lhau
vermelho P
JuJu Mentina
branco M
Amaro Dinha
vermelho P
Adabi Filho
branco G
Severina Rigudinha
branco G
Carlos Chade Losna
vermelho P
3
Maria Joao
branco P
Marcio Guess
vermelho P
Maria Jose
branco P
0

Exemplo de Saída:

branco P Cezar Torres Mo
branco P Maria Jose
branco M JuJu Mentina
branco G Adabi Filho
branco G Severina Rigudinha
vermelho P Amaro Dinha
vermelho P Baka Lhau
vermelho P Carlos Chade Losna
vermelho P Mangojata Mancuda

branco P Maria Joao
branco P Maria Jose
vermelho P Marcio Guess
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Estrutura para armazenar os dados de cada camiseta
struct Camiseta {
    string nome;
    string cor;
    char tamanho;
};

// Função que define os critérios de ordenação
bool compara(const Camiseta &a, const Camiseta &b) {

    // Primeiro critério: cor em ordem crescente
    // Segundo critério: tamanho em ordem decrescente
    // Terceiro critério: nome em ordem alfabética

    return a.cor < b.cor ||
           (a.cor == b.cor &&
            a.tamanho > b.tamanho) ||

           (a.cor == b.cor &&
            a.tamanho == b.tamanho &&
            a.nome < b.nome);
}

int main() {
    int n;
    bool primeiro = true;

    // Continua lendo enquanto houver dados e N for diferente de zero
    while (cin >> n && n != 0) {

        // Cria um vetor com a quantidade de camisetas informada
        vector<Camiseta> camisetas(n);

        // Lê os dados de cada camiseta
        for (int i = 0; i < n; i++) {

            // Lê o nome completo do estudante
            getline(cin >> ws, camisetas[i].nome);

            // Lê a cor e o tamanho da camiseta
            cin >> camisetas[i].cor
                >> camisetas[i].tamanho;
        }

        // Ordena o vetor utilizando a função compara
        sort(camisetas.begin(), camisetas.end(), compara);

        // Imprime uma linha em branco entre os casos de teste
        if (!primeiro) {
            cout << "\n";
        }

        primeiro = false;

        // Percorre o vetor utilizando um iterator
        for (auto it = camisetas.begin(); it != camisetas.end(); it++) {

            // Imprime a cor, o tamanho e o nome do estudante
            cout << (*it).cor << " "
                 << (*it).tamanho << " "
                 << (*it).nome << "\n";
        }
    }

    return 0;
}
