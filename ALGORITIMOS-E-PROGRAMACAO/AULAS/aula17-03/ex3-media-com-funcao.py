nt1 = float(input("Insira a nota 1:"))
nt2 = float(input("Insira a nota 2:"))
nt3 = float(input("Insira a nota 3:"))

def calcular_media(nt1, nt2, nt3):
    return (nt1 + nt2 + nt3) / 3

media = calcular_media(nt1, nt2, nt3)
print(f"Média: {media:.2f}")