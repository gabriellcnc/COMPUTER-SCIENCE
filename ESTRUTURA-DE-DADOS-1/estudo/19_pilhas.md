# Pilhas

Uma **pilha** (*stack*) é uma estrutura de dados em que o último elemento inserido é o primeiro a ser removido.

Esse comportamento é chamado de **LIFO** (*Last In, First Out* — último a entrar, primeiro a sair).

Um exemplo do dia a dia é uma pilha de pratos: para retirar um prato do meio, primeiro seria necessário retirar os que estão acima dele.

## Funcionamento

As principais operações de uma pilha são:

| Operação | Função |
|---|---|
| `push` | Insere um elemento no topo |
| `pop` | Remove o elemento do topo |
| `top` | Consulta o elemento do topo, sem remover |
| `empty` | Verifica se a pilha está vazia |
| `size` | Retorna a quantidade de elementos |

Exemplo de sequência:

```text
push(10)  -> [10]
push(20)  -> [10, 20]
push(30)  -> [10, 20, 30]  topo = 30
pop()     -> [10, 20]      topo = 20
```

O topo fica à direita na representação acima. Portanto, `pop()` remove o `30` primeiro.

## Usando `std::stack`

A biblioteca padrão do C++ oferece a estrutura `std::stack`.

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> pilha;

    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    cout << "Topo: " << pilha.top() << endl;

    pilha.pop();

    cout << "Novo topo: " << pilha.top() << endl;
    cout << "Quantidade: " << pilha.size() << endl;

    return 0;
}
```

**Saída:**

```text
Topo: 30
Novo topo: 20
Quantidade: 2
```

Observe que `pop()` não retorna o elemento removido. Para consultar o valor antes de removê-lo, use `top()`.

## Percorrendo e esvaziando uma pilha

`std::stack` não oferece acesso por índice nem iteradores. Uma forma comum de processar todos os elementos é consultar e remover o topo repetidamente.

```cpp
while (!pilha.empty()) {
    cout << pilha.top() << endl;
    pilha.pop();
}
```

Essa operação esvazia a pilha. Se precisar preservar os elementos, faça uma cópia antes de percorrê-la.

## Implementação simples com vetor

Uma pilha também pode ser implementada usando um vetor e uma variável que controla a quantidade de elementos.

```cpp
#include <iostream>
using namespace std;

const int MAX = 5;

struct Pilha {
    int dados[MAX];
    int topo = -1;
};

bool vazia(Pilha &p) {
    return p.topo == -1;
}

bool cheia(Pilha &p) {
    return p.topo == MAX - 1;
}

void push(Pilha &p, int valor) {
    if (cheia(p)) {
        cout << "Pilha cheia!" << endl;
        return;
    }

    p.topo++;
    p.dados[p.topo] = valor;
}

void pop(Pilha &p) {
    if (vazia(p)) {
        cout << "Pilha vazia!" << endl;
        return;
    }

    p.topo--;
}

int top(Pilha &p) {
    if (vazia(p)) {
        cout << "Pilha vazia!" << endl;
        return -1;
    }

    return p.dados[p.topo];
}

int main() {
    Pilha p;

    push(p, 10);
    push(p, 20);
    push(p, 30);

    cout << "Topo: " << top(p) << endl;
    pop(p);
    cout << "Novo topo: " << top(p) << endl;

    return 0;
}
```

Nesse exemplo, `topo` começa em `-1`, indicando que não existe elemento. Ao inserir, ele é incrementado antes de armazenar o valor. Ao remover, é decrementado.

## Aplicações de pilhas

- Histórico de desfazer/refazer ações.
- Verificação de parênteses e delimitadores em expressões.
- Controle de chamadas de funções e recursão (pilha de execução).
- Navegação de voltar em alguns históricos.
- Conversão e avaliação de expressões matemáticas.

### Relação com recursão e Stack Overflow

Quando uma função chama outra função — inclusive quando chama a si mesma — o programa precisa guardar informações das chamadas em uma pilha de execução.

Uma recursão sem condição de parada pode gerar chamadas continuamente e consumir a memória disponível para essa pilha, causando **stack overflow**. Isso é diferente de uma pilha criada pelo programador com `std::stack`, embora ambas sigam a ideia de LIFO.

## Complexidade das operações

| Operação | Complexidade usual |
|---|---:|
| `push` | O(1) |
| `pop` | O(1) |
| `top` | O(1) |
| `empty` | O(1) |
| `size` | O(1) |

## Erros comuns

- Chamar `top()` quando a pilha está vazia.
- Chamar `pop()` quando a pilha está vazia.
- Achar que `pop()` devolve o elemento removido: ele apenas remove.
- Tentar acessar elementos de `std::stack` por índice.
- Confundir a pilha de dados (`std::stack`) com a pilha de execução usada nas chamadas de função.

## Exercício resolvido

**Problema:** insira os números `4`, `7` e `9` em uma pilha. Depois remova um elemento e mostre o topo.

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> p;

    p.push(4);
    p.push(7);
    p.push(9);
    p.pop();

    cout << p.top() << endl;
    return 0;
}
```

**Resultado:** `7`, pois o `9` foi o último a entrar e o primeiro a sair.

## Exercícios para praticar

1. Insira cinco números em uma pilha e mostre-os na ordem em que são removidos.
2. Leia uma palavra e use uma pilha para imprimir seus caracteres em ordem inversa.
3. Leia uma sequência contendo `(` e `)` e verifique se os parênteses estão balanceados usando uma pilha.
4. Explique a diferença entre `top()` e `pop()`.
