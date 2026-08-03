"""Exercício 12: Sequência de Collatz
=======================================
A conjectura de Collatz afirma que, para qualquer inteiro positivo,
a sequência definida abaixo sempre converge para 1:
  - Se n é par:   n → n // 2
  - Se n é ímpar: n → 3 * n + 1

ENTRADA:
  Um inteiro positivo n (o número inicial).

SAÍDA:
  Cada número da sequência em uma linha separada, começando pelo n inicial.
  Última linha: "Passos: X"
  (X = número de transições até chegar em 1, não contando o número inicial)

EXEMPLOS:
  Entrada: 1
    1
    Passos: 0

  Entrada: 6
    6
    3
    10
    5
    16
    8
    4
    2
    1
    Passos: 8

REFLEXÃO: o número 27 leva quantos passos? (experimente!)

ALGORITMO:
  1. exiba n
  2. passos = 0
  3. Enquanto n != 1:
       Se n % 2 == 0: n = n // 2
       Caso contrário: n = 3 * n + 1
       exiba n; passos += 1
  4. exiba f"Passos: {passos}"

CONTEÚDO: while, if/else, lógica iterativa
"""


"""def collatz(n):
    Executa e exibe a sequência de Collatz a partir de n.
    # TODO: exiba cada número da sequência e o total de passos
    pass"""


# --- programa principal ---
# TODO: leia n e chame collatz(n)

n = int(input())

def collatz(n):
    print(n)
    passos = 0
    while n != 1:
        if n % 2 == 0: n = n // 2
        else: n = 3 * n + 1
        print(n)
        passos += 1
    print(f"Passos: {passos}")

collatz(n)