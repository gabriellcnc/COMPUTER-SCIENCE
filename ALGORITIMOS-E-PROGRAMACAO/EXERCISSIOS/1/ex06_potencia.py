"""Exercício 06: Potenciação Iterativa
=======================================
Implemente base**exp usando while (sem usar ** nem pow()).
Por definição: base^0 = 1  e  base^exp = base × base × ... × base (exp vezes).

ENTRADA:
  Linha 1: base (inteiro)
  Linha 2: expoente exp (inteiro não negativo)

SAÍDA:
  "base^exp = RESULTADO"

EXEMPLOS:
  Entrada: 2 / 10  →  2^10 = 1024
  Entrada: 5 / 0   →  5^0 = 1
  Entrada: 3 / 4   →  3^4 = 81

CONTEÚDO: while, funções com return
"""


""""def potencia(base, exp):
    Calcula e retorna base**exp usando while. Não use ** nem pow().
    # TODO: implemente usando while (sem usar ** nem pow())
    pass"""


# --- programa principal ---
# TODO: leia os dados, chame potencia e exiba o resultado

base = int(input())
exp = int(input())

def potencia(base, exp):
    resultado = 1
    contador = 0
    while contador < exp:
        resultado *= base
        contador += 1
    return resultado

result = potencia(base, exp)

print(f"{base}^{exp} = {result}")
