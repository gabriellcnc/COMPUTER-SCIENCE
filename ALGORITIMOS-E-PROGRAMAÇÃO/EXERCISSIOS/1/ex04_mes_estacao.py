"""Exercício 04: Mês e Estação do Ano
=======================================
Leia um inteiro de 1 a 12 (1 = Janeiro, 12 = Dezembro).
Exiba o nome do mês e, na linha seguinte, a estação do ano (hemisfério sul).

ENTRADA:
  Um inteiro de 1 a 12 (ou outro valor para caso inválido).

SAÍDA:
  Linha 1: nome do mês (ex.: "Marco")
  Linha 2: estação ("Verao", "Outono", "Inverno" ou "Primavera")
  Se o número for inválido: "Mes invalido"

MAPEAMENTO (hemisfério sul — Brasil):
  1  → Janeiro    / Verao
  2  → Fevereiro  / Verao
  3  → Marco      / Outono
  4  → Abril      / Outono
  5  → Maio       / Outono
  6  → Junho      / Inverno
  7  → Julho      / Inverno
  8  → Agosto     / Inverno
  9  → Setembro   / Primavera
  10 → Outubro    / Primavera
  11 → Novembro   / Primavera
  12 → Dezembro   / Verao

EXEMPLOS:
  Entrada: 6   →  Junho / Inverno
  Entrada: 12  →  Dezembro / Verao
  Entrada: 13  →  Mes invalido

CONTEÚDO: match / case
"""

# TODO: leia o mês e exiba o nome e a estação (ou "Mes invalido")

num = int(input())

if num == 1:
    mes = "Janeiro"
    estacao = "Verao"
elif num == 2:
    mes = "Fevereiro"
    estacao = "Verao"
elif num == 3:
    mes = "Marco"
    estacao = "Outono"
elif num == 4:
    mes = "Abril"
    estacao = "Outono" 
elif num == 5:
    mes = "Maio"
    estacao = "Outono"
elif num == 6:
    mes = "Junho"
    estacao = "Inverno"
elif num == 7:
    mes = "Julho"
    estacao = "Inverno"
elif num == 8:
    mes = "Agosto"
    estacao = "Inverno"
elif num == 9:
    mes = "Setembro"
    estacao = "Primavera"
elif num == 10:
    mes = "Outubro"
    estacao = "Primavera"
elif num == 11:
    mes = "Novembro"
    estacao = "Primavera"
elif num == 12:
    mes = "Dezembro"
    estacao = "Verao"
else:
    mes = "Mes invalido"
    estacao = ""



print(mes)
print(estacao)