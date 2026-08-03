"""Exercício 11: Cifra de Inversão
====================================
Implemente a cifra de inversão alfabética: cada letra maiúscula é substituída
pela letra que ocupa a posição oposta no alfabeto (A↔Z, B↔Y, C↔X, …).
Caracteres não-letra são mantidos sem alteração.

FÓRMULA para cada letra maiúscula:
  letra_cifrada = chr(ord('Z') - (ord(letra) - ord('A')))

TABELA PARCIAL:
  A(0) ↔ Z(25)   B(1) ↔ Y(24)   C(2) ↔ X(23)   …   M(12) ↔ N(13)

PROPRIEDADE: aplicar a cifra duas vezes restaura a mensagem original.

ENTRADA:
  Uma linha com a mensagem em letras MAIÚSCULAS (pode conter espaços e dígitos).

SAÍDA:
  A mensagem cifrada (apenas o texto resultante).

VERIFICAÇÃO MANUAL (PYTHON):
  P(15) → chr(90-15) = chr(75) = K
  Y(24) → chr(90-24) = chr(66) = B
  T(19) → chr(90-19) = chr(71) = G
  H(7)  → chr(90-7)  = chr(83) = S
  O(14) → chr(90-14) = chr(76) = L
  N(13) → chr(90-13) = chr(77) = M
  Resultado: KBGSLM

EXEMPLOS:
  Entrada: PYTHON    →  KBGSLM
  Entrada: ALGORITMO →  ZOTLIRGNL
  Entrada: ABC 123   →  ZYX 123

CONTEÚDO: for sobre strings, ord(), chr(), funções
"""


"""def cifrar_inversao(mensagem):
    Cifra a mensagem usando inversão alfabética.

    Apenas letras maiúsculas são transformadas. Outros caracteres passam
    sem alteração. Retorna a string cifrada.
    
    resultado = ""
    # TODO: aplique a inversão em cada letra maiúscula e retorne o resultado
    pass"""


# --- programa principal ---
# TODO: leia a mensagem, chame cifrar_inversao e exiba o resultado

mensagem = input()

def cifrar_inversao(mensagem):
    resultado = ""
    for letra in mensagem:
        if 'A' <= letra <= 'Z':
            letra_cifrada = chr(ord('Z') - (ord(letra) - ord('A'))) 
            resultado += letra_cifrada
        else:
            resultado += letra 
    return resultado

cifrada = cifrar_inversao(mensagem)
print(cifrada)