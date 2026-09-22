# Templates

Templates permitem escrever funções genéricas para vários tipos.

## Exemplo

```cpp
template <typename T>
T maior(T a, T b) {
    return (a > b) ? a : b;
}
```

Pode ser usado com `int`, `float`, `double` etc.

```cpp
cout << maior(3, 8) << endl;
cout << maior(2.5, 1.7) << endl;
```

## Template de troca

```cpp
template <typename T>
void trocar(T &a, T &b) {
    T aux = a;
    a = b;
    b = aux;
}
```

## Exercício resolvido

**Problema:** criar uma função genérica que retorne o menor de dois valores.

```cpp
#include <iostream>
using namespace std;

template <typename T>
T menor(T a, T b) {
    if (a < b)
        return a;

    return b;
}

int main() {
    cout << menor(8, 3) << endl;
    cout << menor(5.7, 9.2) << endl;
}
```

**Saída:**

```text
3
5.7
```

## Exercícios para praticar

1. Template `quadrado(T x)`.
2. Template para trocar dois valores.
3. Template que recebe vetor e mostra os elementos.
