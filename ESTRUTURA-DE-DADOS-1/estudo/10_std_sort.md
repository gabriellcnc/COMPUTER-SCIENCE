# `std::sort`

A função `std::sort` está em:

```cpp
#include <algorithm>
```

## Ordem crescente

```cpp
sort(vet, vet + N);
```

Exemplo:

```cpp
int vet[5] = {8, 2, 5, 1, 4};
sort(vet, vet + 5);
```

Resultado:

```text
1 2 4 5 8
```

## Intervalo do `sort`

O intervalo é:

```text
[inicio, fim)
```

Ou seja: inclui o início e **não inclui** o fim.

```cpp
sort(vet + 2, vet + 6);
```

Ordena os índices `2`, `3`, `4` e `5`.

## Ordem decrescente

```cpp
#include <functional>
sort(vet, vet + N, greater<int>());
```

Ou com comparador:

```cpp
bool compara(int a, int b) {
    return a > b;
}
```

```cpp
sort(vet, vet + N, compara);
```

## Exercício resolvido

**Problema:** ordenar somente as posições 1 a 4 de:

```text
9 8 2 7 1 5
```

Código:

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int vet[6] = {9, 8, 2, 7, 1, 5};

    sort(vet + 1, vet + 5);

    for (int x : vet)
        cout << x << " ";
}
```

Elementos ordenados: `8, 2, 7, 1` → `1, 2, 7, 8`.

Resultado final:

```text
9 1 2 7 8 5
```

## Exercícios para praticar

1. Ordene 10 `float` em ordem decrescente.
2. Ordene somente os 3 elementos centrais de um vetor de 7 posições.
3. Crie seu próprio comparador crescente.
