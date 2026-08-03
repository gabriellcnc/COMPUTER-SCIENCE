x = 10 # Variável global

def funcao_externa():
    print("Esta é a função externa.")
    y = 10  # Variável local à funcao_externa

    def funcao_interna():
        print("Esta é a função interna.")
    
    funcao_interna() 
    
    
funcao_externa()

print(x) # // Vai funcionar pois a variável é global

#print(y) // Não vai funcionar pois ela esta dentro do escopo da função externa.

a = 15

if a < 10:
    z = 30 # Variável local ao bloco if
    print("Dentro do bloco if.")
else:
    w = 40 # Variável local ao bloco if
    print("Dentro do bloco else.")

print(z) # Isso vai fincionar apenas quando passar pelo bloco if.
print(w) # Isso vai funcionar apenas quando passar pelo bloco else.

# Por conta disso não deve-se criar variáveis dentro do escopo de if / else.

