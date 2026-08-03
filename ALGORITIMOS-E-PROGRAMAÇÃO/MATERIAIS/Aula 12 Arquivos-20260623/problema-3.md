# Aula 12 - Problema 3

## Lista de dicionarios com lista aninhada: enriquecer registros

**Contexto:** cada aluno tem um campo `notas` que e uma lista. Os campos `media` e `aprovado` estao em `None` e devem ser preenchidos no proprio dicionario. Criterio de aprovacao: media >= 6,0.

```python
turma = [
    {"nome": "Ana",   "notas": [8.0, 9.5, 7.0], "media": None, "aprovado": None},
    {"nome": "Bruno", "notas": [4.5, 5.0, 6.0], "media": None, "aprovado": None},
    {"nome": "Carol", "notas": [9.0, 8.5, 10.0], "media": None, "aprovado": None},
    {"nome": "Diego", "notas": [3.0, 4.0, 5.5], "media": None, "aprovado": None},
]
```

## Passo 1 - Entendendo o acesso aninhado

- Como acessar a lista de notas do segundo aluno? `turma[___][____________________]`
- Como acessar a primeira nota do terceiro aluno? `turma[___][____________________][___]`
- Dado um dicionario `aluno`, como calcular a media das suas notas? `____________________ / ____________________`

## Passo 2 - O padrao ``enriquecer o registro``

Complete as expressoes:

| Expressao | Completar |
| --- | --- |
| `aluno["media"] =` | ____________________ |
| `aluno["aprovado"] =` | ____________________ |

## Passo 3 - Algoritmo

1. Para cada `aluno` na lista `____________________`:
   1. Calcular `media = sum(aluno[____________________]) / len(aluno[____________________])`
   2. Armazenar `aluno[____________________] = round(media, 1)`
   3. Armazenar `aluno[____________________] = media ____________________`
2. Para exibicao: iterar novamente sobre `turma` e acessar `aluno["media"]` e `aluno["aprovado"]`

## Passo 4 - Codigo

```python
for aluno in ____________________:
    media = sum(aluno[____________________]) / len(aluno[____________________])
    aluno[____________________] = round(media, 1)
    aluno[____________________] = media >= ____________________

print(f"{'Nome':<10} {'Media':>6}  Situacao")
for aluno in turma:
    situacao = ____________________ if aluno[____________________] else ____________________
    print(f"{aluno[____________________]:<10} {aluno[____________________]:>6.1f}  {situacao}")
```

## Verificacao

Depois do primeiro `for`, `turma[0]["media"]` deve ser `8.2` e `turma[3]["aprovado"]` deve ser `False`.
