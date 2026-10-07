# Passagem por referência (`&`)

Esse é um ponto importante em C++.

## Passagem por valor

```cpp
void incrementar(int x) {
    x++;
}
```

```cpp
int n = 10;
incrementar(n);
cout << n; // continua 10
```

A função recebeu uma **cópia**.

## Passagem por referência

```cpp
void incrementar(int &x) {
    x++;
}
```

```cpp
int n = 10;
incrementar(n);
cout << n; // 11
```

O `&` faz `x` referenciar a variável original.

### Regra para memorizar

```text
sem &: copia
com &: original
```

## Exercício resolvido: trocar dois valores

```cpp
#include <iostream>
using namespace std;

void trocar(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

int main() {
    int x = 3;
    int y = 8;

    trocar(x, y);

    cout << x << " " << y << endl;
}
```

**Saída:** `8 3`.

## Vetores em funções

```cpp
void dobrar(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        vet[i] *= 2;
    }
}
```

As alterações feitas nos elementos aparecem no vetor original.

## Exercício resolvido: zerar negativos

```cpp
void zerarNegativos(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        if (vet[i] < 0) {
            vet[i] = 0;
        }
    }
}
```

Para `{3, -2, 5, -8}`, o resultado é `{3, 0, 5, 0}`.

## Exercícios para praticar

1. Crie `dobrarNumero(int &x)`.
2. Crie `ordenarDois(int &a, int &b)` para deixar o menor em `a`.
3. Crie uma função que some 1 a cada posição de um vetor.
