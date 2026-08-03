notas = [7.5, 9.0, 5.5, 8.0, 6.5]
maior = 0
indice = 0

for i in range (len(notas)):
    if notas[i] >= maior:
        maior = notas[i]
        indice = i
print(f"A maior nota é: {maior}")
print(f"Ela está no índice: {indice}")
        