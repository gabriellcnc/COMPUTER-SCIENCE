"""Exercício 05: Progressão Aritmética
=======================================
Crie uma função progressao(primeiro, razao, n) que imprime os n primeiros
termos de uma progressão aritmética.
No programa principal, leia os três valores e chame a função.

UMA PROGRESSÃO ARITMÉTICA (PA) é uma sequência onde a diferença entre
termos consecutivos é constante (a razão).
  k-ésimo termo (k de 1 a n): primeiro + (k - 1) * razao

ENTRADA:
  Linha 1: primeiro termo (inteiro)
  Linha 2: razão (inteiro)
  Linha 3: número de termos n (inteiro)

SAÍDA:
  n linhas, cada uma com o valor do respectivo termo da PA.

EXEMPLOS:
  Entrada: 1 / 2 / 5    →  1 / 3 / 5 / 7 / 9
  Entrada: 10 / -3 / 4  →  10 / 7 / 4 / 1

CONTEÚDO: for, range(), funções com parâmetros
"""


"""def progressao(primeiro, razao, n):
    Imprime os n termos da PA com o primeiro termo e razão dados.
    TODO: implemente a progressão aritmética
    pass"""


# --- programa principal ---
# TODO: leia os dados e chame progressao(primeiro, razao, n)

primeiro = int(input())
razao = int(input())
n = int(input())

def progressao(primeiro, razao, n):
    for k in range(1, n + 1):
        termo = primeiro + (k - 1) * razao
        print(termo)
progressao(primeiro, razao, n)