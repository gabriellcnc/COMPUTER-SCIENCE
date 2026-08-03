precos = [25.0, 80.0, 12.0, 45.0, 60.0, 8.0]
media = sum(precos) / len(precos)
indices_acima = []
for i in range(len(precos)):
    if precos[i] > media:
        indices_acima.append(i)
print(f"A média de preço é: {media:.2f}")
print(f"Índices com preços acima da média: {indices_acima}")
print(f"Total: {len(indices_acima)} preços acima da média.")







