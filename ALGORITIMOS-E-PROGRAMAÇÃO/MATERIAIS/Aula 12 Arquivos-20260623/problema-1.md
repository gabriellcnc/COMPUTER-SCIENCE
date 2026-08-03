# Aula 12 - Problema 1

## Lista de dicionarios -> dicionario de listas: agrupar por campo

**Contexto:** a secretaria recebe uma lista plana de alunos e precisa saber quais alunos pertencem a cada curso. Construa `turmas`, um dicionario que mapeia cada curso para a lista de nomes dos seus alunos.

```python
alunos = [
    {"nome": "Ana", "curso": "BCC", "media": 8.5},
    {"nome": "Bruno", "curso": "ADS", "media": 7.0},
    {"nome": "Carlos", "curso": "BCC", "media": 9.2},
    {"nome": "Diana", "curso": "ADS", "media": 6.8},
    {"nome": "Eduardo", "curso": "BCC", "media": 5.5},
    {"nome": "Flavia", "curso": "EC", "media": 8.1},
]
```

## Passo 1 - Modelagem

- Que estrutura usar para `turmas`? ______________________________
- O que sera a chave? ______________________________
- O que sera o valor? ______________________________
- Quantas chaves tera `turmas` ao final? ______________________________

## Passo 2 - Esboco da estrutura esperada

Complete os valores corretos na estrutura de resultado:

```python
turmas = {
    "BCC": [___________, ___________, ___________],
    ___:   [___________, ___________],
    ___:   [___________],
}
```

## Passo 3 - Algoritmo

1. Criar o acumulador: `turmas = ____________________`
2. Para cada ____________________ na lista `alunos`:
   1. Obter `curso = aluno[____________________]`
   2. Se `curso` ____________________ `turmas`: criar `turmas[curso] = ____________________`
   3. ____________________ o nome do aluno a lista `turmas[curso]`

## Passo 4 - Codigo

```python
turmas = {}
for aluno in ____________________:
    curso = aluno[____________________]
    if curso ____________________ turmas:
        turmas[curso] = ____________________
    turmas[____________________].____________________(aluno[____________________])
```

## Verificacao

`print(turmas["BCC"])` deve exibir `['Ana', 'Carlos', 'Eduardo']`.
