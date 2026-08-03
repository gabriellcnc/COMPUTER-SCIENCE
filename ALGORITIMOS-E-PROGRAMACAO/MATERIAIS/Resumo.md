# Resumo de Python — Listas, Matrizes, Conjuntos, Random e Lógica

---

## LISTAS (`list`)

**O que são:**
- Estruturas que armazenam vários valores
- São ordenadas
- Podem ser alteradas (mutáveis)
- Permitem valores repetidos

### Criar lista
```python
numeros = [1, 2, 3, 4]
nomes = ["Ana", "João", "Pedro"]
```

### Acessar elementos
```python
lista[0]   # primeiro elemento
lista[1]   # segundo elemento
lista[-1]  # último elemento
lista[-2]  # penúltimo elemento
```

### Alterar elemento
```python
lista[0] = 100
```

### Adicionar elementos
```python
lista.append(5)       # adiciona no final
lista.insert(0, 10)   # adiciona na posição desejada
```

### Remover elementos
```python
lista.remove(5)  # remove pelo valor
lista.pop()      # remove o último
lista.pop(2)     # remove pelo índice
del lista[0]     # remove pelo índice
```

### Tamanho
```python
len(lista)
```

### Verificar existência
```python
if 5 in lista:
    print("Existe")
```

### Percorrer lista
```python
for item in lista:
    print(item)
```

### Percorrer usando índice
```python
for i in range(len(lista)):
    print(lista[i])
```

### Percorrer usando enumerate
```python
for indice, valor in enumerate(lista):
    print(indice, valor)
```

### Ordenação
```python
lista.sort()
lista.sort(reverse=True)
```

### Funções importantes
```python
sum(lista)   # soma
max(lista)   # maior valor
min(lista)   # menor valor
```

### Fatiamento
```python
lista[1:4]    # do índice 1 ao 3
lista[:3]     # do início ao índice 2
lista[2:]     # do índice 2 ao fim
lista[::-1]   # inverte
```

### Copiar lista
```python
nova = lista.copy()
nova = lista[:]
```

---

## MATRIZES

**O que são:** listas dentro de listas — representam linhas e colunas.

### Exemplo
```python
matriz = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
```
Visualmente:
```
1 2 3
4 5 6
7 8 9
```

### Acessar elementos
```python
matriz[0][0]  # -> 1
matriz[1][2]  # -> 6
```

### Percorrer matriz
```python
for linha in matriz:
    for valor in linha:
        print(valor)
```

### Percorrer por índices
```python
for i in range(len(matriz)):
    for j in range(len(matriz[i])):
        print(matriz[i][j])
```

### Criar matriz vazia
```python
matriz = []
for i in range(3):
    linha = []
    for j in range(4):
        linha.append(0)
    matriz.append(linha)
```

### Somar todos os elementos
```python
soma = 0
for linha in matriz:
    for valor in linha:
        soma += valor
```

### Diagonal principal
```python
for i in range(len(matriz)):
    print(matriz[i][i])
```

---

## CONJUNTOS (`set`)

**O que são:**
- Não possuem ordem
- Não permitem repetição

### Criar conjunto
```python
a = {1, 2, 3}
b = set()
```

### Exemplo — remoção automática de duplicatas
```python
a = {1, 1, 1, 2, 2, 3}
# Resultado: {1, 2, 3}
```

### Adicionar / Remover
```python
conjunto.add(5)
conjunto.remove(5)   # erro se não existir
conjunto.discard(5)  # seguro, não gera erro
```

### Verificar existência
```python
if 3 in conjunto:
    print("Existe")
```

### Operações com conjuntos
```python
a = {1, 2, 3}
b = {3, 4, 5}

a | b   # União      -> {1, 2, 3, 4, 5}
a & b   # Interseção -> {3}
a - b   # Diferença  -> {1, 2}
```

### Remover duplicados de uma lista
```python
lista = [1, 1, 2, 2, 3, 3]
novo = set(lista)
# Resultado: {1, 2, 3}
```

---

## BIBLIOTECA RANDOM

### Importar
```python
import random
```

### Número inteiro aleatório
```python
random.randint(1, 10)   # retorna de 1 até 10
```

### Número decimal aleatório
```python
random.random()          # retorna de 0.0 até 1.0
random.uniform(1, 10)   # decimal em intervalo
```

### Escolher item aleatório
```python
nomes = ["Ana", "João", "Pedro"]
random.choice(nomes)
```

### Embaralhar lista
```python
random.shuffle(nomes)
```

### Escolher vários itens
```python
random.sample(nomes, 2)
```

### Gerar senha simples
```python
import random

senha = ""
for i in range(8):
    senha += str(random.randint(0, 9))
print(senha)
```

---

## LOOPS (REPETIÇÃO)

### FOR
```python
for i in range(5):
    print(i)
# Saída: 0 1 2 3 4

for i in range(1, 6):
    print(i)
# Saída: 1 2 3 4 5

for i in range(0, 11, 2):
    print(i)
# Saída: 0 2 4 6 8 10

for nome in nomes:
    print(nome)
```

### WHILE
```python
contador = 0
while contador < 5:
    print(contador)
    contador += 1
# Saída: 0 1 2 3 4
```
> ⚠️ Se a condição nunca ficar falsa, cria loop infinito.

### BREAK — interrompe o loop
```python
for i in range(10):
    if i == 5:
        break
    print(i)
# Saída: 0 1 2 3 4
```

### CONTINUE — pula a iteração atual
```python
for i in range(5):
    if i == 2:
        continue
    print(i)
# Saída: 0 1 3 4
```

---

## CONDIÇÕES (IF)

```python
if nota >= 9:
    print("Excelente")
elif nota >= 7:
    print("Bom")
else:
    print("Precisa melhorar")
```

---

## OPERADORES

### Comparação
| Operador | Significado     |
|----------|-----------------|
| `==`     | igual           |
| `!=`     | diferente       |
| `>`      | maior           |
| `<`      | menor           |
| `>=`     | maior ou igual  |
| `<=`     | menor ou igual  |

### Lógicos
```python
and   # as duas condições devem ser verdadeiras
or    # apenas uma precisa ser verdadeira
not   # inverte o valor
```

---

## FUNÇÕES IMPORTANTES

```python
len(lista)      # conta elementos
sum(lista)      # soma elementos
max(lista)      # retorna maior valor
min(lista)      # retorna menor valor
sorted(lista)   # ordena sem alterar o original

range(5)        # 0 1 2 3 4
range(1, 6)     # 1 2 3 4 5
range(0, 10, 2) # 0 2 4 6 8
```

---

## PADRÕES QUE MAIS CAEM EM PROVA

### Somar números
```python
soma = 0
for i in lista:
    soma += i
```

### Encontrar maior valor
```python
maior = lista[0]
for i in lista:
    if i > maior:
        maior = i
```

### Encontrar menor valor
```python
menor = lista[0]
for i in lista:
    if i < menor:
        menor = i
```

### Contar pares
```python
pares = 0
for i in lista:
    if i % 2 == 0:
        pares += 1
```

### Contar ímpares
```python
impares = 0
for i in lista:
    if i % 2 != 0:
        impares += 1
```

### Par ou ímpar
```python
if numero % 2 == 0:
    print("Par")
else:
    print("Ímpar")
```

---

## DIFERENÇAS IMPORTANTES

| Característica       | Lista `[]` | Conjunto `{}` |
|----------------------|------------|---------------|
| Ordenada             | ✅          | ❌             |
| Aceita repetidos     | ✅          | ❌             |
| Pode alterar elementos | ✅        | ❌             |
| Uso principal        | Armazenar sequências | Eliminar duplicatas |

---

## ESTRUTURA QUE RESOLVE 80% DAS PROVAS

```python
lista = []

for i in range(5):
    valor = int(input("Digite um número: "))
    lista.append(valor)

soma = 0
for numero in lista:
    soma += numero

media = soma / len(lista)

print("Soma:", soma)
print("Média:", media)

if media >= 7:
    print("Aprovado")
else:
    print("Reprovado")
```

Esse programa usa: variáveis, input, lista, append, for, range, soma, len, média, if, comparação e print.

---

## RESUMÃO PARA DECORAR

```
[]  = lista
{}  = conjunto

append()        → adiciona no final
remove()        → remove pelo valor
pop()           → remove pelo índice
len()           → tamanho
sum()           → soma
max()           → maior
min()           → menor
sort()          → ordenar
in              → verificar existência
range()         → gerar sequência
enumerate()     → índice + valor
set()           → criar conjunto
add()           → adicionar em conjunto

random.randint()  → número aleatório inteiro
random.choice()   → escolha aleatória

matriz[i][j]    → acessar linha e coluna
% 2 == 0        → par
% 2 != 0        → ímpar
```