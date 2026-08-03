# Escreva um programa que leia a nota final e exiba Aprovado (>= 6) ou Reprovado.
# Critério de verificação: para entrada 5.9, deve mostrar Reprovado.

nota = float(input("Insira a nota do aluno:"))

if nota >= 6.0:
    print("APROVADO!")
else:
    print("REPROVADO!")
