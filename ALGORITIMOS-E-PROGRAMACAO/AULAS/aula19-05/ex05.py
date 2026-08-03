compras = ["arroz", "feijão", "arroz", "leite", "feijão", "arroz", "leite", "leite", "leite"]
frequencia = {}
media_freq = 0
valores = []
for item in compras:
    if item in compras:
        frequencia[item] += 1
    else:
        frequencia[item] = 1

for item, val in frequencia.items():
    valores.append(val)
    media_freq = sum(valores) / len(valores)

print(frequencia)
print(media_freq)
