"""Exercício 03: Máximo em Janela Deslizante
=============================================
Dada uma lista de N inteiros e uma janela de tamanho K, encontre o valor
máximo dentro de cada posição possível da janela.

A janela desliza da esquerda para a direita, um passo por vez.
Para uma lista de tamanho N e janela K, há exatamente N - K + 1 posições.

ENTRADA:
  Linha 1: dois inteiros N e K separados por espaço (1 <= K <= N <= 1000)
  Linha 2: N inteiros separados por espaço

SAÍDA:
  Uma linha com os N - K + 1 máximos separados por espaço.

EXEMPLOS:
  Entrada:
    8 3
    2 1 5 3 6 4 8 7
  Saída:
    5 5 6 6 8 8

  Explicação das janelas:
    [2, 1, 5] → max = 5
    [1, 5, 3] → max = 5
    [5, 3, 6] → max = 6
    [3, 6, 4] → max = 6
    [6, 4, 8] → max = 8
    [4, 8, 7] → max = 8

  Entrada:
    5 1
    3 1 4 1 5
  Saída:
    3 1 4 1 5

  (Janela de tamanho 1: cada elemento é seu próprio máximo.)

DICAS:
  - Use um for com range(N - K + 1) para iterar sobre as posições da janela.
  - A cada posição i, a janela é nums[i : i + K].
  - Use max() para encontrar o máximo de cada fatia.
  - Acumule os resultados em uma lista e exiba com " ".join().

CONTEÚDO: listas, slicing, range, max(), list comprehension (opcional)
"""
def debug(v):
    #print(f"DEBUG: {v}")
    pass

def maximos_janela(nums, k):
    """Retorna a lista dos máximos de cada janela de tamanho k.

    Parâmetros:
        nums (list[int]): lista de inteiros.
        k (int): tamanho da janela.

    Retorna:
        list[int]: lista com os máximos de cada posição da janela.
    """
    resultado = []

    for idx_janela in range(len(nums) - k + 1):
      debug(f"idx_janela: {idx_janela}")
      idx_inicial = idx_janela # índice da posição inicial da janela
      idx_final = idx_inicial + k -1 # índice da posição final da janela

      maior = nums[idx_inicial]
      for i in range(idx_inicial, idx_final + 1):
          valor = nums[i]
          if valor > maior:
              maior = valor
      debug(maior)
      resultado.append(maior)

    

    return resultado


def main():
    # n, k = map(int, input().split())
    # nums = list(map(int, input().split()))
    primeira_linha = input()
    segunda_linha = input()

    n, k = primeira_linha.split()
    n = int(n)
    k = int(k)

    num_strs = segunda_linha.split()
    numeros = []
    for n in num_strs:
        numeros.append(int(n))


    debug(f"n: {type(n)}, k: {k}, numeros: {numeros}")

    resultado = maximos_janela(numeros, k)

    resultado_str = ""
    for v in resultado:
        resultado_str += str(v) + " "

    print(" ".join(map(str, resultado)))

main()
