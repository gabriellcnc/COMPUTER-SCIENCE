# Ponteiros

Ponteiros são variáveis que armazenam **endereços de memória** de outras variáveis. Nas aulas, eles aparecem para acessar valores indiretamente, percorrer arrays e trabalhar com memória dinâmica.

## Endereço e valor

```cpp
int a = 10;
int *p = &a;

cout << a << endl;   // valor de a
cout << &a << endl;  // endereço de a
cout << p << endl;   // endereço armazenado em p
cout << *p << endl;  // valor que existe nesse endereço
```

- `&a`: operador que obtém o endereço de `a`.
- `int *p`: declara um ponteiro para `int`.
- `*p`: desreferencia o ponteiro, acessando o valor apontado.

O endereço exibido depende da execução e não deve ser decorado.

## Alterando uma variável pelo ponteiro

```cpp
float n = 1.5;
float *p = &n;

*p = 9.1;
cout << n << endl; // 9.1
```

Como `p` aponta para `n`, alterar `*p` altera a própria variável.

## Mudando o alvo do ponteiro

```cpp
int a = 5, b = 10, c = 20;
int *p = &a;

cout << *p << endl; // 5
p = &b;
cout << *p << endl; // 10
p = &c;
cout << *p << endl; // 20
```

O ponteiro pode apontar para variáveis diferentes, desde que sejam compatíveis com seu tipo.

## Ponteiro para ponteiro

Um ponteiro também ocupa memória e possui um endereço. Podemos guardar esse endereço em outro ponteiro.

```cpp
int a = 10;
int *p = &a;
int **pp = &p;

cout << *p << endl;   // 10
cout << **pp << endl; // 10
```

- `p` aponta para `a`.
- `pp` aponta para `p`.
- `*pp` é o valor de `p` (o endereço de `a`).
- `**pp` chega ao valor de `a`.

## Ponteiros para struct

Use `->` para acessar um membro de uma struct por meio de um ponteiro.

```cpp
struct Aluno {
    int matricula;
    string nome;
};

Aluno a = {909090, "Rafael"};
Aluno *p = &a;

cout << p->matricula << endl;
p->nome = "Max";
cout << a.nome << endl;
```

A expressão `p->nome` equivale a `(*p).nome`.

## Ponteiros e arrays

O nome de um array, em expressões como esta, representa o endereço do primeiro elemento.

```cpp
int v[3] = {10, 20, 30};
int *p = v; // equivalente a &v[0]

cout << *p << endl; // 10
p++;
cout << *p << endl; // 20
p++;
cout << *p << endl; // 30
```

Ao incrementar um ponteiro, ele avança para o próximo elemento do tipo apontado. Não significa necessariamente somar apenas um byte.

## Ponteiro nulo

Quando um ponteiro não aponta para um objeto válido, inicialize-o com `nullptr`.

```cpp
int *p = nullptr;

if (p != nullptr) {
    cout << *p << endl;
}
```

Nunca desreferencie um ponteiro nulo ou um ponteiro que não aponta para uma área válida.

## Erros comuns

- Confundir `p` (endereço) com `*p` (valor apontado).
- Usar um ponteiro sem inicializá-lo.
- Desreferenciar `nullptr`.
- Continuar usando um ponteiro depois que a memória apontada foi liberada.

## Exercício resolvido

**Problema:** leia um inteiro e dobre seu valor usando um ponteiro.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int *p = &n;
    *p *= 2;

    cout << n << endl;
    return 0;
}
```

## Para praticar

1. Declare três inteiros e faça um ponteiro apontar para cada um deles, exibindo os valores.
2. Crie uma struct `Produto` e altere seus campos usando um ponteiro.
3. Percorra um array de cinco inteiros usando aritmética de ponteiros.
