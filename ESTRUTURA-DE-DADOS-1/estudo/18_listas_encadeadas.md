# Listas encadeadas

Uma lista encadeada armazena elementos em nós (*nodes*). Cada nó guarda um valor e ponteiros que ligam esse nó aos demais. Diferentemente de um array, os elementos não precisam ocupar posições consecutivas na memória.

Nas aulas, foi estudada uma lista duplamente encadeada própria e também o contêiner `std::list`.

## Nó de uma lista duplamente encadeada

Cada nó possui:
- `value`: dado armazenado;
- `previous`: ponteiro para o nó anterior;
- `next`: ponteiro para o próximo nó.

```cpp
struct node {
    string value;
    node *previous = nullptr;
    node *next = nullptr;
};
```

A lista mantém informações de controle:

```cpp
struct list {
    int num_nodes = 0;
    node *first = nullptr;
    node *last = nullptr;
};
```

- `first`: primeiro nó (início).
- `last`: último nó (final).
- `num_nodes`: quantidade de nós.
- Em uma lista vazia, `first` e `last` são `nullptr`.
- Em uma lista com um único nó, `first == last`.

## Inserção no início — `push_front`

Ao inserir um nó no início, ele passa a ser o primeiro e aponta para o antigo primeiro.

```cpp
void push_front(const string &s) {
    node *p = new node;
    p->value = s;
    p->previous = nullptr;
    p->next = first;

    if (first != nullptr) {
        first->previous = p;
    }

    first = p;

    if (last == nullptr) {
        last = p;
    }

    num_nodes++;
}
```

O teste `last == nullptr` identifica a lista que estava vazia. Nesse caso, o novo nó também será o último.

## Inserção no final — `push_back`

```cpp
void push_back(const string &s) {
    node *p = new node;
    p->value = s;
    p->next = nullptr;
    p->previous = last;

    if (last != nullptr) {
        last->next = p;
    }

    last = p;

    if (first == nullptr) {
        first = p;
    }

    num_nodes++;
}
```

O novo nó aponta para o antigo último por meio de `previous`. O antigo último passa a apontar para o novo nó por meio de `next`.

## Percorrendo e imprimindo

```cpp
void print() {
    node *p = first;

    while (p != nullptr) {
        cout << '"' << p->value << '"' << " ";
        p = p->next;
    }

    cout << endl;
}
```

A cada repetição, avançamos para o próximo nó. O percurso termina quando o ponteiro chega a `nullptr`.

## Contagem — `count`

Conta quantos nós possuem determinado valor.

```cpp
int count(const string &s) {
    int total = 0;

    for (node *p = first; p != nullptr; p = p->next) {
        if (p->value == s) {
            total++;
        }
    }

    return total;
}
```

## Busca — `find`

Retorna o endereço do primeiro nó com o valor procurado. Se não encontrar, retorna `nullptr`.

```cpp
node* find(const string &s) {
    for (node *p = first; p != nullptr; p = p->next) {
        if (p->value == s) {
            return p;
        }
    }

    return nullptr;
}
```

Uso:

```cpp
node *p = l.find("cc");

if (p != nullptr) {
    cout << p->value << endl;
}
```

## Remoção de um nó — `erase`

Remover exige atualizar os vizinhos e os extremos da lista.

```cpp
void erase(node *p) {
    if (p == nullptr) return;

    if (p->previous != nullptr) {
        p->previous->next = p->next;
    } else {
        first = p->next;
    }

    if (p->next != nullptr) {
        p->next->previous = p->previous;
    } else {
        last = p->previous;
    }

    delete p;
    num_nodes--;
}
```

Observe os quatro casos tratados:
1. O nó possui anterior: o anterior passa a apontar para o próximo.
2. Não possui anterior: era o primeiro, então atualizamos `first`.
3. O nó possui próximo: o próximo passa a apontar para o anterior.
4. Não possui próximo: era o último, então atualizamos `last`.

Assim, a remoção funciona para o primeiro, o último, um nó do meio e também para uma lista com um único elemento.

## Remover todas as ocorrências — `remove`

É necessário guardar o próximo nó antes de apagar o atual, pois não podemos acessar o nó depois de `delete`.

```cpp
void remove(const string &s) {
    node *p = first;

    while (p != nullptr) {
        node *proximo = p->next;

        if (p->value == s) {
            erase(p);
        }

        p = proximo;
    }
}
```

## `std::list`

O C++ também oferece uma lista duplamente encadeada pronta na biblioteca `<list>`.

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> valores;

    valores.push_front(10);
    valores.push_back(20);
    valores.push_front(30);

    for (auto n : valores) {
        cout << n << " ";
    }
}
```

Principais operações:

| Operação | Função |
|---|---|
| `push_front(x)` | Insere no início |
| `push_back(x)` | Insere no final |
| `pop_front()` | Remove o primeiro |
| `pop_back()` | Remove o último |
| `size()` | Retorna a quantidade |
| `remove(x)` | Remove todas as ocorrências de `x` |
| `remove_if(condição)` | Remove elementos que atendem à condição |
| `sort()` | Ordena a própria lista |
| `begin()` / `end()` | Iteradores direto |
| `rbegin()` / `rend()` | Iteradores reversos |

Exemplos de `remove_if` e ordenação:

```cpp
list<int> valores{10, 200, 41, 20, -18};

valores.remove_if([](int n) {
    return n % 2 == 0;
});

valores.sort([](int a, int b) {
    return a < b;
});
```

A função `sort()` é membro de `std::list`. Não use `std::sort` da biblioteca `<algorithm>` diretamente com `std::list`, pois seus iteradores não oferecem acesso aleatório.

## `advance` e `count_if`

```cpp
#include <iterator>
#include <algorithm>

auto it = valores.begin();
advance(it, 2); // avança duas posições

int quantidade = count_if(
    valores.begin(),
    valores.end(),
    [](int n) { return n > 150; }
);
```

- `advance(it, 2)` avança o iterador duas posições.
- `count_if` conta os elementos que satisfazem a condição.
- A expressão `[](int n) { return n > 150; }` é uma função lambda.

## Cuidados importantes

- Atualize `first`, `last` e a quantidade de nós em cada inserção e remoção.
- Em lista vazia, os extremos devem ser `nullptr`.
- Não use um nó depois de liberar sua memória com `delete`.
- Antes de apagar um nó durante um percurso, guarde o endereço do próximo.
- Não desreferencie um iterador igual a `end()`.

## Para praticar

1. Implemente `push_front` e `push_back` em uma lista duplamente encadeada.
2. Implemente `count` e `find`.
3. Implemente `erase` considerando remoção do início, meio, fim e lista com um único nó.
4. Implemente `remove` para apagar todas as ocorrências de um valor.
5. Faça os mesmos testes usando `std::list<int>`.
