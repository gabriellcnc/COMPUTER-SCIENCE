"""Exercício 03: Calculadora de Desconto
==========================================
Leia o preço original de um produto e aplique o desconto conforme a faixa.

TABELA DE DESCONTOS:
  preço < 50.00          →  0% de desconto
  50.00 <= preço < 100   →  5% de desconto
  100.00 <= preço < 200  →  10% de desconto
  preço >= 200.00        →  15% de desconto

ENTRADA:
  Uma linha com o preço original (float).

SAÍDA:
  "Desconto: X%"
  "Preco final: Y.YY"

EXEMPLOS:
  Entrada: 30.00   →  Desconto: 0%  / Preco final: 30.00
  Entrada: 80.00   →  Desconto: 5%  / Preco final: 76.00
  Entrada: 150.00  →  Desconto: 10% / Preco final: 135.00
  Entrada: 300.00  →  Desconto: 15% / Preco final: 255.00

CONTEÚDO: if / elif / else, float, f-strings com :.2f
"""

# TODO: leia o preço, determine o desconto e exiba os resultados

preco = float(input())
if preco < 50.00:
    desconto = 0
elif preco < 100.00:
    desconto = 5
elif preco < 200.00:
    desconto = 10
else:
    desconto = 15

preco_final = preco - (preco * desconto / 100)

print(f"Desconto: {desconto}%")
print(f"Preco final: {preco_final:.2f}")