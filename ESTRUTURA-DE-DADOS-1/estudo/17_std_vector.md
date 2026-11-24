# `std::vector`

O `std::vector` é um contêiner da biblioteca padrão do C++ que funciona como um vetor redimensionável. Diferentemente de um array tradicional, pode aumentar ou diminuir sua quantidade de elementos durante a execução.

Para utilizá-lo:

```cpp
#include <vector>
```

## Criando um vector

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);
```

`push_back()` adiciona um elemento ao final.

## Acessando e percorrendo

```cpp
for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
}
```

Também podemos usar range-for:

```cpp
for (auto valor : v) {
    cout << valor << endl;
}
```

Nesse formato, `valor` recebe uma cópia de cada elemento. Para alterar os elementos, use referência:

```cpp
for (auto &valor : v) {
    valor *= 2;
}
```

## `size()` e `capacity()`

São conceitos diferentes e importantes.

- `size()`: quantidade atual de elementos armazenados.
- `capacity()`: quantidade de elementos que o espaço atualmente reservado consegue comportar sem nova realocação.

```cpp
vector<double> v;

cout << v.size() << " " << v.capacity() << endl;

v.push_back(2.5);
cout << v.size() << " " << v.capacity() << endl;
```

A capacidade inicial e a estratégia de crescimento podem variar conforme a implementação. Não decore valores específicos de `capacity()`.

## Criando com tamanho inicial

```cpp
int n = 3;
vector<string> nomes(n);

nomes[0] = "Ana";
nomes[1] = "Bruno";
nomes[2] = "Carla";

nomes.push_back("Davi");
```

`vector<string> nomes(n)` cria um vector com `n` elementos. Depois do `push_back`, o tamanho aumenta em um.

## Removendo elementos

```cpp
v.pop_back(); // remove o último elemento
```

`pop_back()` não retorna o elemento removido. Verifique se o vector não está vazio antes de remover.

## Iteradores

Iteradores permitem percorrer posições do contêiner.

```cpp
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << endl;
}
```

- `begin()`: iterador para o primeiro elemento.
- `end()`: posição logo após o último elemento; não deve ser desreferenciada.
- `*it`: elemento da posição indicada.

Para percorrer ao contrário:

```cpp
for (auto it = v.rbegin(); it != v.rend(); it++) {
    cout << *it << endl;
}
```

`rbegin()` e `rend()` são os limites dos iteradores reversos.

## Busca com `find()`

A função `find()` está em `<algorithm>` e retorna um iterador para a primeira ocorrência encontrada.

```cpp
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<string> v = {"A", "B", "C", "F", "H"};

    auto it = find(v.begin(), v.end(), "F");

    if (it == v.end()) {
        cout << "Nao encontrado" << endl;
    } else {
        cout << "Encontrado: " << *it << endl;
    }
}
```

Se o resultado for igual a `v.end()`, o elemento não foi encontrado.

## Inserindo e limpando

```cpp
auto it = find(v.begin(), v.end(), "F");

if (it != v.end()) {
    v.insert(it, "Z"); // insere antes da posição indicada
}

v.clear(); // remove todos os elementos
```

`clear()` deixa o vector vazio (`size() == 0`), mas não garante que a capacidade seja zerada.

## Resumo dos métodos

| Método | Função |
|---|---|
| `push_back(x)` | Adiciona `x` ao final |
| `pop_back()` | Remove o último |
| `size()` | Retorna a quantidade de elementos |
| `capacity()` | Retorna a capacidade reservada |
| `begin()` / `end()` | Iteradores direto |
| `rbegin()` / `rend()` | Iteradores reversos |
| `insert(it, x)` | Insere antes de `it` |
| `clear()` | Remove todos os elementos |

## Para praticar

1. Leia números até receber zero e armazene-os em um `vector<int>`.
2. Exiba o tamanho e a capacidade após cada inserção.
3. Busque um número com `find()` e insira outro antes dele.
4. Percorra um vector usando índice, range-for e iterador.
