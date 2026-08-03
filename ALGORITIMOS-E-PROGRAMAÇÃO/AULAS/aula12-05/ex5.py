precos = [25.0, 80.0, 12.0, 45.0, 60.0, 8.0]
media = sum(precos) / len(precos)
acima_da_meida = 0
for i in range (len(precos)):
    if precos[i] > media:
        acima_da_meida += 1
print(f"A média de preço é: {media:.2f}")
print(f"{acima_da_meida} notas estão acima da média.")