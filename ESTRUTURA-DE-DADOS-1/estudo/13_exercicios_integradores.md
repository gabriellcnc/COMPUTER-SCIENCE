# Exercícios integradores

Aqui os assuntos aparecem juntos, como em uma prova.

# Exercício 1 — Tempos de atletas

## Enunciado

Leia os tempos de `N` atletas e mostre:

- quantidade com tempo menor que 11;
- quantidade entre 11 e 12;
- quantidade com 12 ou mais;
- melhor tempo;
- pior tempo;
- média;
- tempos em ordem decrescente.

## Solução

```cpp
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

float calcularMedia(float vet[], int n) {
    float soma = 0;

    for (int i = 0; i < n; i++) {
        soma += vet[i];
    }

    return soma / n;
}

int main() {
    const int N = 5;
    float tempo[N];

    int excelentes = 0;
    int bons = 0;
    int melhorar = 0;

    for (int i = 0; i < N; i++) {
        cin >> tempo[i];

        if (tempo[i] < 11)
            excelentes++;
        else if (tempo[i] < 12)
            bons++;
        else
            melhorar++;
    }

    float melhor = tempo[0];
    float pior = tempo[0];

    for (int i = 1; i < N; i++) {
        if (tempo[i] < melhor)
            melhor = tempo[i];

        if (tempo[i] > pior)
            pior = tempo[i];
    }

    float media = calcularMedia(tempo, N);

    sort(tempo, tempo + N, greater<float>());

    cout << fixed << setprecision(2);
    cout << "Excelentes: " << excelentes << endl;
    cout << "Bons: " << bons << endl;
    cout << "Melhorar: " << melhorar << endl;
    cout << "Melhor tempo: " << melhor << endl;
    cout << "Pior tempo: " << pior << endl;
    cout << "Media: " << media << endl;

    for (float t : tempo)
        cout << t << " ";
}
```

### Atenção

Em corrida, o **menor tempo é o melhor**.

---

# Exercício 2 — Ranking de alunos

## Enunciado

Crie um vetor de alunos e ordene por nota decrescente. Em empate, use nome crescente.

## Solução

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct Aluno {
    int matricula;
    string nome;
    float nota;
};

bool compara(const Aluno &a, const Aluno &b) {
    if (a.nota != b.nota)
        return a.nota > b.nota;

    return a.nome < b.nome;
}

int main() {
    Aluno turma[4] = {
        {1, "Bruno", 9.0},
        {2, "Ana", 9.0},
        {3, "Carla", 8.5},
        {4, "Daniel", 10.0}
    };

    sort(turma, turma + 4, compara);

    for (const Aluno &a : turma) {
        cout << a.nome << " - " << a.nota << endl;
    }
}
```

Saída:

```text
Daniel - 10
Ana - 9
Bruno - 9
Carla - 8.5
```

---

# Exercício 3 — Complete mentalmente

```cpp
int vet[] = {5, 1, 4, 2};

for (int i = 0; i < 3; i++) {
    if (vet[i] > vet[i + 1])
        swap(vet[i], vet[i + 1]);
}
```

Após a passagem, o vetor será:

```text
1 4 2 5
```

Isso é uma passagem de Bubble Sort.

## Desafios sem solução imediata

1. Faça um cadastro de 5 produtos e ordene por preço.
2. Crie uma matriz 3x3 e guarde a soma de cada linha em um vetor.
3. Implemente Bubble, Selection e Insertion no mesmo programa e compare os resultados.
4. Crie `struct Atleta` com nome e tempo e ordene do melhor para o pior tempo.
5. Ordene alunos por três critérios: nota, nome e matrícula.
