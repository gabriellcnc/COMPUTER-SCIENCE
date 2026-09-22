# Selection Sort

O Selection Sort escolhe o menor elemento da parte ainda não ordenada e o coloca na posição correta.

## Exemplo

```text
7 3 5 1
```

Menor elemento: `1`.

Troca com a primeira posição:

```text
1 3 5 7
```

Depois o algoritmo continua a partir do índice 1.

## Código

```cpp
#include <utility>

template <typename T>
void selectionSort(T vet[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int posMenor = i;

        for (int j = i + 1; j < n; j++) {
            if (vet[j] < vet[posMenor]) {
                posMenor = j;
            }
        }

        std::swap(vet[i], vet[posMenor]);
    }
}
```

## Ponto-chave

Quando encontramos um novo menor:

```cpp
posMenor = j;
```

Guardamos o **índice** dele.

## Exercício resolvido

Ordene a primeira etapa de:

```text
9 4 7 2 6
```

- posição inicial: `i = 0`
- menor encontrado: `2`, índice 3
- troca `vet[0]` com `vet[3]`

Resultado:

```text
2 4 7 9 6
```

## Código de teste

```cpp
#include <iostream>
#include <utility>
using namespace std;

int main() {
    int vet[] = {9, 4, 7, 2, 6};
    int n = 5;

    for (int i = 0; i < n - 1; i++) {
        int posMenor = i;

        for (int j = i + 1; j < n; j++) {
            if (vet[j] < vet[posMenor])
                posMenor = j;
        }

        swap(vet[i], vet[posMenor]);
    }

    for (int x : vet)
        cout << x << " ";
}
```

## Exercícios para praticar

1. Implemente Selection Sort decrescente.
2. Conte o número de trocas.
3. Mostre `posMenor` em cada etapa.
