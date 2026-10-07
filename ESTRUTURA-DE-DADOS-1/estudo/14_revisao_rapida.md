# Revisão rápida para prova

## Vetores

```cpp
int vet[5];
```

Índices válidos:

```text
0 1 2 3 4
```

Percorrer:

```cpp
for (int i = 0; i < 5; i++)
    cout << vet[i];
```

## Matriz

```cpp
m[i][j]
```

`i` = linha, `j` = coluna.

## Funções

```cpp
int soma(int a, int b) {
    return a + b;
}
```

## Referência

```cpp
void alterar(int &x)
```

`&` → altera o original.

## Bubble Sort

```cpp
if (vet[i] > vet[i + 1])
    swap(vet[i], vet[i + 1]);
```

**Palavra-chave:** vizinhos.

## Selection Sort

```cpp
if (vet[j] < vet[posMenor])
    posMenor = j;
```

**Palavra-chave:** seleciona o menor.

## Insertion Sort

```cpp
while (j >= 0 && vet[j] > aux)
```

**Palavra-chave:** insere no lugar certo.

## `std::sort`

```cpp
sort(vet, vet + N);
```

Crescente.

```cpp
sort(vet, vet + N, greater<int>());
```

Decrescente.

## Comparadores

```cpp
return a < b; // crescente
return a > b; // decrescente
```

## Struct

```cpp
struct Aluno {
    string nome;
    float nota;
};
```

Acesso:

```cpp
turma[i].nota
```

## Exercício resolvido relâmpago

**Pergunta:** complete para ordenar notas do maior para o menor.

```cpp
bool compara(float a, float b) {
    return ________;
}
```

**Resposta:**

```cpp
bool compara(float a, float b) {
    return a > b;
}
```

Porque o comparador diz que `a` deve vir antes de `b` quando `a` for maior.

## Checklist

Antes da prova, confirme se você consegue escrever sem consultar:

- um `for` para percorrer vetor;
- soma, média, maior e menor;
- função com retorno;
- função com parâmetro por referência;
- Bubble Sort;
- Selection Sort;
- Insertion Sort;
- `sort(vet, vet + N)`;
- uma `struct`;
- comparador de `struct` com dois critérios.
