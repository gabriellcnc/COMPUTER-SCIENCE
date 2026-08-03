"""Exercício 08: Calculadora de Esfera
=======================================
Use o módulo math para calcular volume e área superficial de uma esfera.

FÓRMULAS:
  Volume          = (4/3) × π × r³
  Área superficial = 4 × π × r²

ENTRADA:
  O raio da esfera (float).

SAÍDA:
  "Volume: X.XX"
  "Area: X.XX"

EXEMPLOS:
  Entrada: 1  →  Volume: 4.19  / Area: 12.57
  Entrada: 3  →  Volume: 113.10 / Area: 113.10

CONTEÚDO: módulo math, funções com return, f-strings formatadas
"""

"""import math


def volume_esfera(raio):
    Retorna o volume da esfera: (4/3) * math.pi * raio ** 3.
    # TODO: implemente a fórmula usando math.pi
    pass


def area_esfera(raio):
    Retorna a área superficial da esfera: 4 * math.pi * raio ** 2.
    # TODO: implemente a fórmula usando math.pi
    pass"""


# --- programa principal ---
# TODO: leia o raio, chame as funções e exiba os resultados


import math

raio = float(input())

def volume_esfera(raio):
  return (4/3) * math.pi * raio ** 3

def area_esfera(raio):
  return 4 * math.pi * raio ** 2

volume = volume_esfera(raio)
area = area_esfera(raio)

print(f"Volume: {volume:.2f}")
print(f"Area: {area:.2f}")