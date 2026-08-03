#Crie uma função dobro(numero) que retorna o dobro do valor recebido.
#Critério de verificação: para dobro(7), o resultado deve ser 14.


valor = float(input("Insira o valor:"))

def calcula_dobro(valor):
    return valor * 2

resultado = calcula_dobro(valor)
print (f"O dobro de {valor} é {resultado}. ")