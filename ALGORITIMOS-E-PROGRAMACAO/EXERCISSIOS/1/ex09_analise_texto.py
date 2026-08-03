"""Exercício 09: Analisador de Texto
=====================================
Analise um texto caractere por caractere e conte vogais, consoantes,
dígitos e espaços.

ENTRADA:
  Uma linha com o texto a ser analisado (pode conter letras, dígitos e espaços).

SAÍDA (nessa ordem exata):
  "Vogais: N"
  "Consoantes: N"
  "Digitos: N"
  "Espacos: N"

DEFINIÇÕES:
  Vogais:     a, e, i, o, u (maiúsculas e minúsculas)
  Consoantes: letras que não são vogais
  Dígitos:    0–9
  Espaços:    caractere ' '

EXEMPLOS:
  Entrada: Python 3
    Vogais: 1
    Consoantes: 5
    Digitos: 1
    Espacos: 1

  Entrada: Hello World 123
    Vogais: 3
    Consoantes: 7
    Digitos: 3
    Espacos: 2

DICA: use c.lower() in "aeiou" para verificar vogais.

CONTEÚDO: for sobre strings, condicionais, funções, any()
"""

"""VOGAIS = "aeiouAEIOU"


def analisar_texto(texto):
    Conta vogais, consoantes, dígitos e espaços no texto.

    Retorna uma tupla (vogais, consoantes, digitos, espacos).
    
    vogais = consoantes = digitos = espacos = 0
    # TODO: percorra o texto e conte cada tipo de caractere
    return vogais, consoantes, digitos, espacos"""


# --- programa principal ---
# TODO: leia o texto, chame analisar_texto e exiba os contadores

texto = input()

vogais = "aeiouAEIOU"

def analisar_texto(texto):
  contar_vogais = contar_consoantes = contar_digitos = contar_espacos = 0
  for c in texto:
    if c in vogais:
      contar_vogais += 1
    elif c.isalpha():
      contar_consoantes += 1
    elif c.isdigit():
      contar_digitos += 1
    elif c == ' ':
      contar_espacos += 1
  return contar_vogais, contar_consoantes, contar_digitos, contar_espacos

vogais, consoantes, digitos, espacos = analisar_texto(texto)
print(f"Vogais: {vogais}")
print(f"Consoantes: {consoantes}")
print(f"Digitos: {digitos}")
print(f"Espacos: {espacos}")