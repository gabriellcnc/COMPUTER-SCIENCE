"""Exercício 01: Classificador de Triângulo
============================================
Dados três lados, verifique se formam um triângulo válido e, se sim,
classifique-o pelo tipo.

CONDIÇÃO DE VALIDADE:
  Um triângulo é válido se a soma de quaisquer dois lados for
  maior que o terceiro:  a + b > c  AND  a + c > b  AND  b + c > a

CLASSIFICAÇÃO:
  "Equilatero"        →  os três lados são iguais
  "Isosceles"         →  exatamente dois lados são iguais
  "Escaleno"          →  todos os lados são diferentes
  "Nao e triangulo"   →  condição de validade não satisfeita

ENTRADA:
  Linha 1: lado a (float)
  Linha 2: lado b (float)
  Linha 3: lado c (float)

SAÍDA:
  Exatamente uma das classificações acima.

EXEMPLOS:
  Entrada: 3 / 3 / 3    →  Saída: Equilatero
  Entrada: 5 / 5 / 8    →  Saída: Isosceles
  Entrada: 3 / 4 / 5    →  Saída: Escaleno
  Entrada: 1 / 2 / 10   →  Saída: Nao e triangulo

CONTEÚDO: if / else, operadores and / or / not, float
"""

# TODO: leia os três lados
# TODO: verifique se formam um triângulo e classifique-o


a = float(input())
b = float(input())
c = float(input())

if a + b > c and a + c > b and b + c > a:
    if a == b == c:
        print("Equilatero")
    elif a == b or a == c or b == c:
        print("Isosceles")
    else:
        print("Escaleno")

else:
    print("Nao e triangulo")
    