precos = {"caneta": 2.50, "caderno": 15.90, "borracha": 1.20, "mochila": 89.90}
preco = 0
produto = ""

for prod, val in precos.items():
    if val > preco:
        preco = val
        produto = prod

print(f"O produto de maior valor é: {produto} R${preco:.2f}")
    



    