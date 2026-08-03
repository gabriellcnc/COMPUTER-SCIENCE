"""Exercício 02: Classificador de Temperatura
==============================================
Leia uma temperatura em graus Celsius e classifique-a em uma de cinco faixas.

ENTRADA:
  Uma linha com a temperatura em Celsius (float).

SAÍDA (exatamente uma das strings abaixo):
  "Muito frio"    →  temp < 0
  "Frio"          →  0 <= temp < 15
  "Agradavel"     →  15 <= temp < 25
  "Quente"        →  25 <= temp < 35
  "Muito quente"  →  temp >= 35

EXEMPLOS:
  Entrada: -5.0  →  Saída: Muito frio
  Entrada: 10.0  →  Saída: Frio
  Entrada: 20.0  →  Saída: Agradavel
  Entrada: 30.0  →  Saída: Quente
  Entrada: 40.0  →  Saída: Muito quente

CONTEÚDO: if / elif / else com múltiplas faixas, float
"""

# TODO: leia a temperatura e exiba a classificação correspondente


temp = float(input())

if temp < 0:
    print("Muito frio")
elif temp < 15:
    print("Frio")
elif temp < 25:
    print("Agradavel")
elif temp < 35:
    print("Quente")
else:
    print("Muito quente")