# Aula 12 - Problema 5

## Dicionario de listas de dicionarios: tres niveis

**Contexto:** o cardapio de uma lanchonete esta organizado em categorias. Cada categoria contem uma lista de itens. Voce deve: (a) exibir o cardapio mostrando apenas itens disponiveis; (b) calcular o preco medio dos itens disponiveis por categoria.

```python
cardapio = {
    "Lanches": [
        {"nome": "X-Burguer", "preco": 18.90, "disponivel": True},
        {"nome": "X-Veggie", "preco": 17.50, "disponivel": True},
        {"nome": "Hot Dog", "preco": 12.00, "disponivel": False},
    ],
    "Bebidas": [
        {"nome": "Suco Natural", "preco": 8.50, "disponivel": True},
        {"nome": "Refrigerante", "preco": 5.00, "disponivel": True},
        {"nome": "Agua", "preco": 3.00, "disponivel": False},
    ],
    "Sobremesas": [
        {"nome": "Sorvete", "preco": 10.00, "disponivel": True},
        {"nome": "Brownie", "preco": 12.50, "disponivel": False},
    ],
}
```

## Passo 1 - Entendendo os tres niveis

- `cardapio`: ____________________
- `cardapio["Lanches"]`: ____________________
- `cardapio["Lanches"][0]`: ____________________
- Como acessar o preco do X-Veggie? `cardapio[____________________][____________________][____________________]`
- No laço `for categoria, itens in cardapio.items()`: o que e `itens`? ____________________
- Para percorrer cada item de cada categoria precisamos de quantos `for` aninhados? ____________________

## Passo 2 - Condicao de filtragem

Para exibir apenas itens disponiveis, a condicao dentro do `for` interno e:

```python
if item[____________________]:
```

Isso equivale a testar se o campo ____________________ e ____________________.

## Passo 3 - Algoritmo - tarefa (b): media por categoria

1. Para cada `categoria, itens` em `cardapio.items()`:
   1. Construir lista `disponiveis` com itens onde `item[____________________]` e verdadeiro
   2. Se `disponiveis` nao estiver vazia:
   3. Calcular `media = sum(item[____________________] for item in disponiveis) / len(____________________)`
   4. Imprimir categoria e media

## Passo 4 - Codigo

```python
# Tarefa a: exibir menu disponivel
for categoria, itens in cardapio.____________________():
    print(f"\n=== {categoria} ===")
    for item in ____________________:
        if item[____________________]:
            print(f"  {item[____________________]}: R$ {item[____________________]:.2f}")

# Tarefa b: preco medio dos disponiveis por categoria
for categoria, itens in cardapio.items():
    disponiveis = [item for item in ____________________ if item[____________________]]
    if ____________________:
        media = sum(item[____________________] for item in disponiveis) / len(____________________)
        print(f"{categoria}: media R$ {media:.2f}")
```

## Verificacao

`"Hot Dog"` nao deve aparecer na tarefa (a). Na tarefa (b), a media de Lanches deve ser `R$ 18.20` e de Sobremesas deve ser `R$ 10.00`.
