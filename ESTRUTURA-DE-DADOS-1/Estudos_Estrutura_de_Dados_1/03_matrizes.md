# Matrizes

Matrizes são vetores com duas dimensões: linhas e colunas.

```cpp
int m[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

`m[1][2]` vale `6`.

## Percorrendo uma matriz

```cpp
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        cout << m[i][j] << " ";
    }
    cout << endl;
}
```

Normalmente:

- `i` representa a linha;
- `j` representa a coluna.

## Inicialização correta de uma matriz 3x3

```cpp
float m[3][3] = {
    {1.5, 0.4, 9.1},
    {0.6, 1.4, 10.2},
    {8.7, 1.7, 15.3}
};
```

## Exercício resolvido

**Problema:** calcular a soma de todos os elementos de uma matriz 2x3.

```cpp
#include <iostream>
using namespace std;

int main() {
    int m[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int soma = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            soma += m[i][j];
        }
    }

    cout << "Soma: " << soma << endl;
}
```

**Resultado:** `1 + 2 + 3 + 4 + 5 + 6 = 21`.

## Exercícios para praticar

1. Leia uma matriz 3x3 e mostre a diagonal principal.
2. Conte quantos elementos são pares.
3. Encontre o maior valor da matriz.
