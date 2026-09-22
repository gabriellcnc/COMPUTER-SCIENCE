# Insertion Sort

O Insertion Sort mantém uma parte do vetor ordenada e insere cada novo elemento no lugar correto.

Pense em organizar cartas na mão.

## Exemplo

```text
6 2 4 8
```

Processando `2`:

```text
2 6 4 8
```

Processando `4`:

```text
2 4 6 8
```

## Código

```cpp
template <typename T>
void insertionSort(T vet[], int n) {
    for (int i = 1; i < n; i++) {
        T aux = vet[i];
        int j = i - 1;

        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j--;
        }

        vet[j + 1] = aux;
    }
}
```

## Por que `vet[j] > aux`?

Para ordem crescente, valores maiores que a chave `aux` precisam ser deslocados para a direita.

## Exercício resolvido

Considere:

```text
3 7 4 6
```

Ao processar `4`:

1. `aux = 4`
2. `7 > 4`, então `7` vai uma posição para a direita.
3. `3 > 4` é falso.
4. `4` entra depois do `3`.

Resultado parcial:

```text
3 4 7 6
```

## Código de teste

```cpp
#include <iostream>
using namespace std;

int main() {
    int vet[] = {3, 7, 4, 6};
    int n = 4;

    for (int i = 1; i < n; i++) {
        int aux = vet[i];
        int j = i - 1;

        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j--;
        }

        vet[j + 1] = aux;
    }

    for (int x : vet)
        cout << x << " ";
}
```

## Exercícios para praticar

1. Faça Insertion Sort decrescente.
2. Mostre o vetor após cada inserção.
3. Teste com um vetor que já esteja quase ordenado.
