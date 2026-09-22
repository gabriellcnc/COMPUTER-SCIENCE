# Structs

Uma `struct` reúne dados relacionados de tipos diferentes.

```cpp
struct Aluno {
    int matricula;
    string nome;
    float nota;
};
```

## Criando e preenchendo

```cpp
Aluno a;
a.matricula = 123;
a.nome = "Ana";
a.nota = 9.5;
```

Ou:

```cpp
Aluno a = {123, "Ana", 9.5};
```

## Vetor de structs

```cpp
Aluno turma[3] = {
    {101, "Ana", 8.5},
    {102, "Bruno", 7.0},
    {103, "Carla", 9.2}
};
```

Acesso:

```cpp
cout << turma[2].nota;
```

Isso acessa a nota do **terceiro** aluno.

## Percorrendo

```cpp
for (int i = 0; i < 3; i++) {
    cout << turma[i].nome << " - " << turma[i].nota << endl;
}
```

## Exercício resolvido

**Problema:** encontrar o aluno com maior nota.

```cpp
#include <iostream>
using namespace std;

struct Aluno {
    int matricula;
    string nome;
    float nota;
};

int main() {
    Aluno turma[3] = {
        {101, "Ana", 8.5},
        {102, "Bruno", 7.0},
        {103, "Carla", 9.2}
    };

    int posMaior = 0;

    for (int i = 1; i < 3; i++) {
        if (turma[i].nota > turma[posMaior].nota) {
            posMaior = i;
        }
    }

    cout << turma[posMaior].nome << endl;
    cout << turma[posMaior].nota << endl;
}
```

**Resultado:** Carla, nota 9.2.

## Exercícios para praticar

1. Crie `struct Produto` com nome, preço e estoque.
2. Leia 5 produtos e mostre o mais caro.
3. Calcule a média das notas de um vetor de alunos.
