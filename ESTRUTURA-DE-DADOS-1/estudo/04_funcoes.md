# Funções

Funções dividem o programa em partes reutilizáveis.

## Função com retorno

```cpp
int somar(int a, int b) {
    return a + b;
}
```

Uso:

```cpp
int resultado = somar(10, 5);
```

## Função `void`

```cpp
void imprimir(string texto) {
    cout << texto << endl;
}
```

`void` significa que a função não retorna um valor.

## Escopo

```cpp
int somar(int a, int b) {
    int resultado = a + b;
    return resultado;
}
```

`resultado` existe somente dentro da função.

## Exercício resolvido: fatorial

**Problema:** criar uma função que calcule `n!`.

```cpp
#include <iostream>
using namespace std;

int fatorial(int n) {
    int resultado = 1;

    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}

int main() {
    cout << fatorial(5) << endl;
}
```

**Raciocínio:** `5! = 1 × 2 × 3 × 4 × 5 = 120`.

## Exercício resolvido: média de vetor

```cpp
float calcularMedia(float vet[], int n) {
    float soma = 0;

    for (int i = 0; i < n; i++) {
        soma += vet[i];
    }

    return soma / n;
}
```

## Exercícios para praticar

1. Função `maior(int a, int b)`.
2. Função que recebe vetor e retorna o menor valor.
3. Função que conta números pares de um vetor.
