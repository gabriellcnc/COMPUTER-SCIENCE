# Vetores

Um vetor armazena vários valores do mesmo tipo.

```cpp
int vet[5] = {10, 20, 30, 40, 50};
```

Os índices são:

```text
indice:  0   1   2   3   4
valor:  10  20  30  40  50
```

## Percorrendo

```cpp
for (int i = 0; i < 5; i++) {
    cout << vet[i] << " ";
}
```

## Boa prática: constante para tamanho

```cpp
const int N = 5;
int vet[N];
```

## Soma e média

```cpp
int soma = 0;
for (int i = 0; i < N; i++) {
    soma += vet[i];
}

double media = static_cast<double>(soma) / N;
```

## Maior e menor

```cpp
int menor = vet[0];
int maior = vet[0];

for (int i = 1; i < N; i++) {
    if (vet[i] < menor) menor = vet[i];
    if (vet[i] > maior) maior = vet[i];
}
```

### Erro comum

Para `int vet[5]`, `vet[5]` é inválido. Os índices válidos vão de `0` a `4`.

## Exercício resolvido

**Problema:** dado `{7, 2, 9, 4, 1}`, mostre menor, maior e soma.

```cpp
#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    int vet[N] = {7, 2, 9, 4, 1};

    int soma = 0;
    int menor = vet[0];
    int maior = vet[0];

    for (int i = 0; i < N; i++) {
        soma += vet[i];

        if (vet[i] < menor)
            menor = vet[i];

        if (vet[i] > maior)
            maior = vet[i];
    }

    cout << "Soma: " << soma << endl;
    cout << "Menor: " << menor << endl;
    cout << "Maior: " << maior << endl;
}
```

**Resultado:** soma `23`, menor `1`, maior `9`.

## Exercícios para praticar

1. Leia 8 números e mostre-os em ordem inversa.
2. Conte quantos valores são maiores que 10.
3. Encontre a posição do maior elemento.
