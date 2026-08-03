"""Exercício 07: Calculadora de Frequência
==========================================
Leia n registros de presença (1 = presente, 0 = ausente),
calcule a frequência percentual e determine a situação do aluno.

ENTRADA:
  Linha 1: número de aulas n (inteiro)
  Linhas 2 a n+1: registro de cada aula (1 ou 0)

SAÍDA:
  "Frequencia: X.XX%"
  "Situacao: Aprovado"  ou  "Situacao: Reprovado"

CRITÉRIO: frequencia >= 75.0% → Aprovado, caso contrário → Reprovado

EXEMPLOS:
  Entrada: 4 / 1 / 1 / 1 / 0  →  Frequencia: 75.00% / Situacao: Aprovado
  Entrada: 4 / 1 / 0 / 0 / 0  →  Frequencia: 25.00% / Situacao: Reprovado

CONTEÚDO: for, funções compostas, if/else
"""


"""def calcular_frequencia(registros):
    Recebe uma lista de 0s e 1s e retorna o percentual de presença.
    # TODO: calcule e retorne o percentual de presença
    pass


def classificar_frequencia(frequencia):
    Retorna 'Aprovado' se frequencia >= 75.0, 'Reprovado' caso contrário.
    # TODO: retorne 'Aprovado' ou 'Reprovado'
    pass
"""

# --- programa principal ---
# TODO: leia os dados, chame as funções e exiba os resultados


n = int(input())
registros = []
for _ in range(n):
    registro = int(input())
    registros.append(registro)

def calcular_frequencia(registros):
    total_aulas = len(registros)
    aulas_presentes = sum(registros)
    frequencia = (aulas_presentes / total_aulas) * 100
    return frequencia

def classificar_frequencia(frequencia):
    if frequencia >= 75.0:
        return "Aprovado"
    else:
        return "Reprovado"

frequencia = calcular_frequencia(registros)
situacao = classificar_frequencia(frequencia)

print(f"Frequencia: {frequencia:.2f}%")
print(f"Situacao: {situacao}")