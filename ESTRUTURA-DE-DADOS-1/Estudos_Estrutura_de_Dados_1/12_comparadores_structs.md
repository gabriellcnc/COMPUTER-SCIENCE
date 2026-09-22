# Comparadores e ordenação de structs

Para ordenar structs com `std::sort`, criamos uma função comparadora.

## Exemplo: nota decrescente

```cpp
bool compara(const Aluno &a, const Aluno &b) {
    return a.nota > b.nota;
}
```

Uso:

```cpp
sort(turma, turma + N, compara);
```

## Por que `const Aluno &`?

```cpp
const Aluno &a
```

- `&`: evita copiar a struct inteira;
- `const`: garante que o comparador não altere o objeto.

## Vários critérios

Desejo:

1. maior nota primeiro;
2. se empatar, nome em ordem alfabética;
3. se ainda empatar, matrícula crescente.

Forma clara:

```cpp
bool compara(const Aluno &a, const Aluno &b) {
    if (a.nota != b.nota)
        return a.nota > b.nota;

    if (a.nome != b.nome)
        return a.nome < b.nome;

    return a.matricula < b.matricula;
}
```

## Erro comum

No terceiro critério, só podemos comparar matrícula quando **nota e nome já são iguais**.

Não use uma condição que ainda diga `a.nome < b.nome` para entrar no terceiro critério.

## Exercício resolvido

**Problema:** ordenar produtos por preço crescente e, em empate, nome crescente.

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct Produto {
    string nome;
    float preco;
};

bool compara(const Produto &a, const Produto &b) {
    if (a.preco != b.preco)
        return a.preco < b.preco;

    return a.nome < b.nome;
}

int main() {
    Produto produtos[4] = {
        {"Mouse", 100},
        {"Teclado", 200},
        {"Cabo", 50},
        {"Adaptador", 100}
    };

    sort(produtos, produtos + 4, compara);

    for (const Produto &p : produtos) {
        cout << p.nome << " - " << p.preco << endl;
    }
}
```

Ordem esperada:

```text
Cabo - 50
Adaptador - 100
Mouse - 100
Teclado - 200
```

## Exercícios para praticar

1. Alunos: nota crescente; empate por nome.
2. Produtos: estoque decrescente; empate por preço crescente.
3. Pessoas: idade crescente; empate por nome crescente.
