/*
Crie um programa em C++ que defina uma struct para representar produtos de uma loja. 
Cada produto deve ter os seguintes atributos:

Nome do produto (string)
Preço (float)
Quantidade em estoque (int)
O programa deve:

Ler as informações de N produtos.
Permitir que o usuário escolha uma das seguintes opções de ordenação:
Ordenar os produtos por nome (em ordem alfabética).
Ordenar os produtos por preço (em ordem crescente).
Ordenar os produtos por quantidade em estoque (em ordem decrescente).
Exibir a lista de produtos ordenada de acordo com a opção escolhida.


Exemplo de Entrada:

3

Arroz 10.50 100
Feijao 8.75 50
Macarrao 5.20 200
Opção de ordenação: 2

Exemplo de Saída:

Macarrao - Preço: 5.20 - Quantidade: 200
Feijao - Preço: 8.75 - Quantidade: 50
Arroz - Preço: 10.50 - Quantidade: 100
*/

```cpp
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct produto {
    string nome;
    float preco;
    int quantidade;
};

bool comparaNome(const produto &p1, const produto &p2) {
    return p1.nome < p2.nome;
}

bool comparaPreco(const produto &p1, const produto &p2) {
    return p1.preco < p2.preco;
}

bool comparaQuantidade(const produto &p1, const produto &p2) {
    return p1.quantidade > p2.quantidade;
}

int main() {
    int N;
    int opcao;

    cin >> N;

    produto produtos[N];

    for (int i = 0; i < N; i++) {
        cin >> produtos[i].nome
            >> produtos[i].preco
            >> produtos[i].quantidade;
    }

    cin >> opcao;

    if (opcao == 1) {
        sort(produtos, produtos + N, comparaNome);
    }
    else if (opcao == 2) {
        sort(produtos, produtos + N, comparaPreco);
    }
    else if (opcao == 3) {
        sort(produtos, produtos + N, comparaQuantidade);
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < N; i++) {
        cout << produtos[i].nome
             << " - Preço: " << produtos[i].preco
             << " - Quantidade: " << produtos[i].quantidade
             << endl;
    }

    return 0;
}
```
