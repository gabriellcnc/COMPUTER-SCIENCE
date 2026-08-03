# Aula 12 - Problema 4

## Dicionario de dicionarios: navegar, filtrar e agrupar

**Contexto:** o estoque esta organizado como um dicionario de dicionarios. Voce deve: (a) listar produtos abaixo do estoque minimo; (b) calcular o valor total do estoque por categoria.

```python
estoque = {
    "notebook": {"qtd": 10, "preco": 3500.00, "categoria": "eletronicos", "minimo": 5},
    "mouse":    {"qtd":  3, "preco":   80.00, "categoria": "eletronicos", "minimo": 10},
    "caderno":  {"qtd": 45, "preco":   12.90, "categoria": "papelaria",   "minimo": 20},
    "caneta":   {"qtd":  8, "preco":    2.50, "categoria": "papelaria",   "minimo": 50},
    "mochila":  {"qtd":  2, "preco":   89.90, "categoria": "acessorios",  "minimo": 5},
    "pendrive": {"qtd": 15, "preco":   45.00, "categoria": "eletronicos", "minimo": 8},
}
```

## Passo 1 - Entendendo a navegacao

- Como acessar o preco do notebook? `estoque[____________________][____________________]`
- No laço `for produto, dados in estoque.items()`: o que fica em `produto`? ____________________
- Em `dados`? ____________________
- Como verificar se um produto esta abaixo do minimo dado o dicionario `dados`? `dados[____________________] < dados[____________________]`

## Passo 2 - Esboco: tarefa (a)

Inspecione os dados e liste os produtos que estao **abaixo do minimo**:

```python
abaixo_minimo = [____________________, ____________________, ____________________]
```

Por que esses tres? ____________________

## Passo 3 - Algoritmo - tarefa (b): valor por categoria

1. Criar `valor_cat = {}`
2. Para cada `produto, dados` em `estoque.____________________()`:
   1. Obter `cat = dados[____________________]`
   2. Se `cat` ____________________ `valor_cat`: `valor_cat[cat] = ____________________`
   3. `valor_cat[____________________]` acumula `dados[____________________] * dados[____________________]`

## Passo 4 - Codigo

```python
# Tarefa a: produtos abaixo do minimo
abaixo = []
for produto, dados in estoque.____________________():
    if dados[____________________] < dados[____________________]:
        abaixo.____________________(produto)

# Tarefa b: valor total por categoria
valor_cat = {}
for produto, dados in estoque.items():
    cat = dados[____________________]
    if cat ____________________ valor_cat:
        valor_cat[cat] = ____________________
    valor_cat[____________________] += dados[____________________] * dados[____________________]
```

## Verificacao

`abaixo` deve conter `"mouse"`, `"caneta"` e `"mochila"`. `valor_cat["eletronicos"]` deve ser `35915.0`.
