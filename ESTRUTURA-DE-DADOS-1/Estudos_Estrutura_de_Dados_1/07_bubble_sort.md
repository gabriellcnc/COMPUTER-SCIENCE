# Bubble Sort

O Bubble Sort compara **elementos vizinhos** e os troca quando estão fora de ordem.

## Ideia

Para ordem crescente:

```text
5 2 4 1
```

Primeira passagem:

```text
5 2  -> troca -> 2 5 4 1
5 4  -> troca -> 2 4 5 1
5 1  -> troca -> 2 4 1 5
```

O maior valor chegou ao final.

## Código

```cpp
#include <utility>

template <typename T>
void bubbleSort(T vet[], int n) {
    bool trocou;

    do {
        trocou = false;

        for (int i = 0; i < n - 1; i++) {
            if (vet[i] > vet[i + 1]) {
                std::swap(vet[i], vet[i + 1]);
                trocou = true;
            }
        }
    } while (trocou);
}
```

### Condição fundamental

```cpp
if (vet[i] > vet[i + 1])
```

Para crescente, se o valor da esquerda é maior que o da direita, os dois devem trocar.

## Exercício resolvido

**Problema:** execute uma passagem de Bubble Sort em `{6, 3, 5, 2}`.

1. `6 > 3` → troca: `{3, 6, 5, 2}`
2. `6 > 5` → troca: `{3, 5, 6, 2}`
3. `6 > 2` → troca: `{3, 5, 2, 6}`

Resultado após a primeira passagem:

```text
3 5 2 6
```

## Código completo de teste

```cpp
#include <iostream>
#include <utility>
using namespace std;

void bubbleSort(int vet[], int n) {
    bool trocou;

    do {
        trocou = false;
        for (int i = 0; i < n - 1; i++) {
            if (vet[i] > vet[i + 1]) {
                swap(vet[i], vet[i + 1]);
                trocou = true;
            }
        }
    } while (trocou);
}

int main() {
    int vet[] = {6, 3, 5, 2};
    bubbleSort(vet, 4);

    for (int x : vet)
        cout << x << " ";
}
```

## Exercícios para praticar

1. Faça Bubble Sort decrescente.
2. Mostre o vetor depois de cada troca.
3. Conte quantas trocas foram realizadas.
