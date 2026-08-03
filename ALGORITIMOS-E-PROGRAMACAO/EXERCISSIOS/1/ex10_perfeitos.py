"""Exercício 10: Números Perfeitos
====================================
Um número perfeito é igual à soma de seus divisores próprios
(todos os divisores exceto ele mesmo).
Use math.sqrt para tornar a verificação mais eficiente.

EXEMPLOS DE NÚMEROS PERFEITOS:
  6    →  divisores próprios: 1, 2, 3  →  1+2+3 = 6  ✓
  28   →  divisores próprios: 1, 2, 4, 7, 14  →  28  ✓
  496  →  perfeito  ✓

POR QUÊ math.sqrt?  Para encontrar todos os divisores de n,
  basta testar d de 2 até √n. Se d divide n, então n//d também
  é divisor. Isso reduz complexidade de O(n) para O(√n).

ENTRADA:
  Um inteiro n (limite superior, inclusive).

SAÍDA:
  Cada número perfeito encontrado em uma linha separada.
  Última linha: "Total: X numeros"

EXEMPLOS:
  Entrada: 10   →  6 / Total: 1 numeros
  Entrada: 500  →  6 / 28 / 496 / Total: 3 numeros

CONTEÚDO: for, math.sqrt, int(), funções booleanas
"""

#import math


"""def eh_perfeito(n):
    Retorna True se n for um número perfeito, False caso contrário.

    Algoritmo:
      - n < 2 nunca é perfeito
      - Inicialize soma = 1 (o divisor 1 sempre existe para n > 1)
      - Teste divisores d de 2 até int(math.sqrt(n)) + 1
      - Se n % d == 0: some d e, se d != n // d, some n // d também
      - Se soma == n → True; caso contrário → False
    
    # TODO: implemente usando math.sqrt para eficiência
    pass"""


# --- programa principal ---
# TODO: percorra os números até n, exiba os perfeitos e o total

import math

n = int(input())

def eh_perfeito(n):
    if n < 2:
        return False
    soma = 1
    for d in range(2, int(math.sqrt(n)) + 1): # testando divisores de 2 até √n
        if n % d == 0: # d é divisor
            soma += d # soma o divisor d
            if d != n // d: 
                soma += n // d
    return soma == n

total_perfeitos = 0
for i in range(1, n + 1): # testando números de 1 até n
    if eh_perfeito(i): # se i é perfeito, exibe e conta
        print(i) 
        total_perfeitos += 1 #
print(f"Total: {total_perfeitos} numeros")