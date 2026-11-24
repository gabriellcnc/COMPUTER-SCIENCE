# Filas

Uma **fila** (*queue*) é uma estrutura de dados em que o primeiro elemento inserido é o primeiro a ser removido.

Esse comportamento é chamado de **FIFO** (*First In, First Out* — primeiro a entrar, primeiro a sair).

Um exemplo do dia a dia é uma fila de atendimento: normalmente, a primeira pessoa que chega é a primeira a ser atendida.

## Funcionamento

As principais operações de uma fila são:

| Operação | Função |
|---|---|
| `push` | Insere um elemento no final da fila |
| `pop` | Remove o elemento do início da fila |
| `front` | Consulta o primeiro elemento, sem remover |
| `back` | Consulta o último elemento, sem remover |
| `empty` | Verifica se a fila está vazia |
| `size` | Retorna a quantidade de elementos |

Exemplo de sequência:

```text
push(10)  -> início [10] fim
push(20)  -> início [10, 20] fim
push(30)  -> início [10, 20, 30] fim
pop()     -> início [20, 30] fim
```

O `10` foi removido porque era o primeiro elemento inserido.

## Usando `std::queue`

A biblioteca padrão do C++ oferece a estrutura `std::queue`.

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> fila;

    fila.push(10);
    fila.push(20);
    fila.push(30);

    cout << "Primeiro: " << fila.front() << endl;
    cout << "Ultimo: " << fila.back() << endl;

    fila.pop();

    cout << "Novo primeiro: " << fila.front() << endl;
    cout << "Quantidade: " << fila.size() << endl;

    return 0;
}
```

**Saída:**

```text
Primeiro: 10
Ultimo: 30
Novo primeiro: 20
Quantidade: 2
```

Assim como `std::stack`, o `pop()` de `std::queue` não retorna o elemento removido. Use `front()` para consultar o primeiro elemento antes de removê-lo.

## Percorrendo e esvaziando uma fila

`std::queue` não oferece acesso por índice nem iteradores. Para processar os elementos na ordem de atendimento, consulte e remova o início repetidamente.

```cpp
while (!fila.empty()) {
    cout << fila.front() << endl;
    fila.pop();
}
```

Esse processo esvazia a fila.

## Implementação simples com vetor circular

Uma fila pode ser implementada em um vetor. Para aproveitar os espaços liberados pelas remoções, podemos tratar o vetor como circular: depois da última posição, a próxima volta para o índice zero.

```cpp
#include <iostream>
using namespace std;

const int MAX = 5;

struct Fila {
    int dados[MAX];
    int inicio = 0;
    int quantidade = 0;
};

bool vazia(Fila &f) {
    return f.quantidade == 0;
}

bool cheia(Fila &f) {
    return f.quantidade == MAX;
}

void enqueue(Fila &f, int valor) {
    if (cheia(f)) {
        cout << "Fila cheia!" << endl;
        return;
    }

    int fim = (f.inicio + f.quantidade) % MAX;
    f.dados[fim] = valor;
    f.quantidade++;
}

void dequeue(Fila &f) {
    if (vazia(f)) {
        cout << "Fila vazia!" << endl;
        return;
    }

    f.inicio = (f.inicio + 1) % MAX;
    f.quantidade--;
}

int front(Fila &f) {
    if (vazia(f)) {
        cout << "Fila vazia!" << endl;
        return -1;
    }

    return f.dados[f.inicio];
}

int main() {
    Fila f;

    enqueue(f, 10);
    enqueue(f, 20);
    enqueue(f, 30);

    cout << "Primeiro: " << front(f) << endl;
    dequeue(f);
    cout << "Novo primeiro: " << front(f) << endl;

    return 0;
}
```

Nessa implementação:

- `inicio` guarda a posição do primeiro elemento.
- `quantidade` informa quantos elementos estão na fila.
- A posição de inserção é calculada com `(inicio + quantidade) % MAX`.
- O operador `%` permite voltar ao começo do vetor quando o final é alcançado.

## Aplicações de filas

- Atendimento de pessoas por ordem de chegada.
- Impressão de documentos enviados para uma impressora.
- Processamento de tarefas em ordem de solicitação.
- Filas de mensagens e requisições em sistemas.
- Busca em largura (*BFS*) em grafos.

## Complexidade das operações

| Operação | Complexidade usual |
|---|---:|
| `push` | O(1) |
| `pop` | O(1) |
| `front` | O(1) |
| `back` | O(1) |
| `empty` | O(1) |
| `size` | O(1) |

## Erros comuns

- Chamar `front()` ou `back()` quando a fila está vazia.
- Chamar `pop()` quando a fila está vazia.
- Achar que `pop()` devolve o elemento removido: ele apenas remove.
- Confundir o início da fila (remoção) com o final (inserção).
- Implementar fila em vetor sem reutilizar as posições liberadas, desperdiçando espaço.

## Exercício resolvido

**Problema:** insira os números `5`, `8` e `12` em uma fila. Depois remova um elemento e mostre o primeiro.

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> f;

    f.push(5);
    f.push(8);
    f.push(12);
    f.pop();

    cout << f.front() << endl;
    return 0;
}
```

**Resultado:** `8`, pois o `5` foi o primeiro a entrar e foi removido primeiro.

## Exercícios para praticar

1. Insira cinco nomes em uma fila e mostre a ordem em que serão atendidos.
2. Simule uma fila de atendimento: permita inserir pessoas e atender a próxima.
3. Explique a diferença entre `front()` e `back()`.
4. Compare uma fila implementada em vetor circular com uma fila implementada usando `std::queue`.
