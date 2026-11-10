/*
Depois de um belo dia de aula é função das vans levarem os estudantes para suas respectivas casas. 
Mas o que muitos não sabem é que além dos gastos e manutenção da van 
o motorista precisa ter uma rota para entregar os passageiros em suas casas. C
omo você é o menino(a) da informática, ele pediu sua ajuda para desenvolver essa rota ordenando os alunos pela distância(da menor para a maior), 
pela região (em ordem alfabética) e por último pelo nome. 

Entrada
Ele te dá a quantidade Q de alunos que não faltaram, 
o nome do aluno A e uma sigla para a região onde ele mora S ("L" Leste, "N" Norte, "O" Oeste, "S" Sul), 
e C que representa o custo da entrada da cidade até sua casa. A saída dos casos será (EOF).

Saída
A saída será uma lista das pessoas na ordem em que devem ser entregadas.

Exemplo de Entrada:
5 
Samuel O 1 
Fabricio L 1 
Emanuel S 3 
Kaio S 20 
Hugo N 90 

Exemplo de Saída:
Fabricio 
Samuel 
Emanuel 
Kaio 
Hugo 
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Estrutura para armazenar os dados de cada aluno
struct Aluno {
    string nome;
    char regiao;
    int distancia;
};

// Função que define os critérios de ordenação
bool compara(const Aluno &a, const Aluno &b) {

    // Primeiro critério: menor distância
    // Segundo critério: região em ordem alfabética
    // Terceiro critério: nome em ordem alfabética
    return a.distancia < b.distancia ||
           (a.distancia == b.distancia &&
            a.regiao < b.regiao) ||

           (a.distancia == b.distancia &&
            a.regiao == b.regiao &&
            a.nome < b.nome);
}

int main() {
    int n;

    // Continua lendo enquanto houver dados na entrada (EOF)
    while (cin >> n) {

        // Cria um vetor com a quantidade de alunos informada
        vector<Aluno> alunos(n);

        // Lê os dados de cada aluno
        for (int i = 0; i < n; i++) {
            cin >> alunos[i].nome
                >> alunos[i].regiao
                >> alunos[i].distancia;
        }

        // Ordena o vetor utilizando a função compara
        sort(alunos.begin(), alunos.end(), compara);

        // Percorre o vetor utilizando um iterator
        for (auto it = alunos.begin(); it != alunos.end(); it++) {

            // Imprime o nome do aluno apontado pelo iterator
            cout << (*it).nome << endl;
        }
    }

    return 0;
}
