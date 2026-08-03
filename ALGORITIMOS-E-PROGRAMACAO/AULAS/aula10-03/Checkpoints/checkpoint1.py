# Escreva um programa que leia uma idade e informe se a pessoa é maior de idade.
# Critério de verificação: para entrada 18, a saída deve indicar maioridade.

idade = int(input("Digite sua idade:"))

if idade >= 18:
    print("Maioridade")
else:
    print("Menor de Idade")