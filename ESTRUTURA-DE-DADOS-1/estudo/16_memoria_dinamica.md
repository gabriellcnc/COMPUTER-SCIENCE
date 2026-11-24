# Memória dinâmica

A memória dinâmica permite solicitar espaço durante a execução do programa. Nas aulas, foram usados `new` para alocar e `delete` para liberar memória.

## Variáveis automáticas e estáticas

Uma variável local comum é criada quando a execução entra no seu escopo e deixa de existir quando esse escopo termina.

```cpp
void exemplo() {
    int n = 0;
    n++;
    cout << n << endl;
}
```

Chamando essa função várias vezes, a variável local comum começa novamente em zero a cada chamada.

Com `static`, a variável mantém seu valor entre chamadas:

```cpp
void exemplo() {
    static int n = 0;
    n++;
    cout << n << endl;
}
```

Chamadas sucessivas exibem `1`, `2`, `3`... A variável estática mantém sua duração durante todo o programa.

## Alocação dinâmica com `new` e `delete`

```cpp
int *p = new int;
*p = 25;

cout << *p << endl;

delete p;
p = nullptr;
```

- `new int` solicita memória para um inteiro e retorna seu endereço.
- `p` guarda esse endereço.
- `delete p` libera a memória solicitada.
- Depois de liberar, não use o ponteiro como se ainda apontasse para um objeto válido.

## Alocando arrays

Para reservar espaço para vários elementos, use `new[]`.

```cpp
int n = 5;
float *v = new float[n];

for (int i = 0; i < n; i++) {
    cin >> v[i];
}

delete[] v;
v = nullptr;
```

A liberação de um array deve usar `delete[]`, e não `delete`.

## Exemplo: soma de valores

```cpp
#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    float *v = new float[N];
    float soma = 0;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        soma += v[i];
    }

    cout << "Soma: " << soma << endl;

    delete[] v;
    v = nullptr;
    return 0;
}
```

## Vazamento de memória

Um vazamento acontece quando a memória dinâmica deixa de ser acessível sem ter sido liberada.

```cpp
int *p = new int;
*p = 35;

p = nullptr; // exemplo de perda do endereço: a memória não foi liberada
```

Ao sobrescrever o único ponteiro que guardava o endereço, perdemos a possibilidade de liberar aquela área. O programa continua com a memória alocada até o encerramento do processo.

## Stack overflow e recursão

Uma chamada de função mantém informações de execução. Uma recursão sem condição de parada pode acumular chamadas até esgotar a pilha.

```cpp
void repetir(int n) {
    cout << n << endl;
    repetir(n + 1); // não existe condição de parada
}
```

Esse exemplo pode causar stack overflow. Toda recursão deve ter um caso-base que encerre as chamadas.

## Diferenças importantes

| Operação | Uso |
|---|---|
| `new int` | Aloca um elemento |
| `delete p` | Libera um elemento alocado com `new` |
| `new int[n]` | Aloca um array |
| `delete[] p` | Libera um array alocado com `new[]` |

## Cuidados para a prova

- Não confunda o endereço guardado no ponteiro com o valor apontado.
- Cada alocação dinâmica deve ter sua liberação correspondente.
- Use `delete` com `new` e `delete[]` com `new[]`.
- Não acesse memória depois de liberá-la.
- Não perca o endereço da memória alocada antes de liberá-la.

## Para praticar

1. Aloque dinamicamente um inteiro, leia um valor, exiba-o e libere a memória.
2. Leia `N` valores em um array dinâmico e calcule a média.
3. Explique por que sobrescrever o único ponteiro de uma alocação pode causar vazamento.
