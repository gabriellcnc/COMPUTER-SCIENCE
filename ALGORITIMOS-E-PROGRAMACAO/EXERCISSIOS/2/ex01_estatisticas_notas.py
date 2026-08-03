"""Exercício 01: Estatísticas de Notas da Turma
================================================
Dado um conjunto de N notas de alunos, calcule e exiba:
  - A menor nota da turma
  - A maior nota da turma
  - A mediana das notas
  - O número de alunos aprovados (nota >= 6.0)

A MEDIANA é o valor central de uma lista ordenada:
  - Se N for ímpar: é o elemento do meio.
  - Se N for par: é a MÉDIA dos dois elementos centrais.

ENTRADA:
  Linha 1: inteiro N (quantidade de notas, 1 <= N <= 100)
  Linha 2: N números reais separados por espaço (as notas, entre 0.0 e 10.0)

SAÍDA:
  Quatro linhas, nesta ordem:
    Menor: X.X
    Maior: X.X
    Mediana: X.X
    Aprovados: K

  Todos os valores numéricos com exatamente 1 casa decimal.

EXEMPLOS:
  Entrada:
    5
    7.0 4.5 9.0 6.5 8.0
  Saída:
    Menor: 4.5
    Maior: 9.0
    Mediana: 7.0
    Aprovados: 4

  Entrada:
    4
    5.0 3.0 7.0 9.0
  Saída:
    Menor: 3.0
    Maior: 9.0
    Mediana: 6.0
    Aprovados: 2

DICAS:
  - Use sorted() para ordenar as notas.
  - O índice do elemento central (N ímpar) é N // 2.
  - Para N par, os centrais são os índices N//2 - 1 e N//2.
  - Itere a lista com um for para contar aprovados.

CONTEÚDO: listas, sorted(), slicing, enumerate, len()
"""


def calcular_estatisticas(notas):
    notas = sorted(notas)
    maior = max(notas)
    menor = min(notas)
    mediana = 0.0
    aprovados = 0

    for nota in notas:
        if nota >= 6.0:
            aprovados += 1
    
    if len(notas) % 2 == 1:
        mediana = notas[len(notas) // 2]
    else:
        mediana = (notas[len(notas) // 2 - 1] + notas[len(notas) // 2]) / 2
    return menor, maior, mediana, aprovados

def main():
    n = int(input())
    notas = list(map(float, input().split()))

    menor, maior, mediana, aprovados = calcular_estatisticas(notas)
    print(f"Menor: {menor:.1f}")
    print(f"Maior: {maior:.1f}")
    print(f"Mediana: {mediana:.1f}")
    print(f"Aprovados: {aprovados}")


main()
