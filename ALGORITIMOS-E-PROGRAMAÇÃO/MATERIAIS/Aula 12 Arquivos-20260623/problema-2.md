# Aula 12 - Problema 2

## Lista de dicionarios -> dicionario de dicionarios: acumular por entidade

**Contexto:** uma lista de vendas registra cada transacao com vendedor, produto e valor. Construa `relatorio`, onde cada chave e o nome de um vendedor e o valor e um dicionario com `qtd` e `faturamento`.

```python
vendas = [
    {"vendedor": "Lucas", "produto": "Notebook", "valor": 3500.00},
    {"vendedor": "Maria", "produto": "Mouse",    "valor":   80.00},
    {"vendedor": "Lucas", "produto": "Teclado",  "valor":  150.00},
    {"vendedor": "Maria", "produto": "Monitor",  "valor":  900.00},
    {"vendedor": "Pedro", "produto": "Notebook", "valor": 3500.00},
    {"vendedor": "Lucas", "produto": "Caneta",   "valor":    2.50},
    {"vendedor": "Maria", "produto": "Caderno",  "valor":   12.90},
    {"vendedor": "Pedro", "produto": "Mouse",    "valor":   80.00},
]
```

## Passo 1 - Modelagem

- Que campo da venda se torna a chave de `relatorio`? ____________________
- Quais campos acumular por vendedor? ____________________ e ____________________
- Como inicializar o registro de um vendedor novo? ____________________

## Passo 2 - Esboco

Calcule e preencha os valores finais:

| Vendedor | qtd | faturamento |
| --- | --- | --- |
| `Lucas` | ___ | ___ |
| `Maria` | ___ | ___ |
| `Pedro` | ___ | ___ |

## Passo 3 - Algoritmo

1. Criar `relatorio = {}`
2. Para cada `venda` em `vendas`:
   1. Obter `v = venda[____________________]`
   2. Se `v` ____________________ `relatorio`: `relatorio[v] = {"qtd": ____________________, "faturamento": ____________________}`
   3. Incrementar `relatorio[v][____________________]` em ____________________
   4. Somar `venda[____________________]` a `relatorio[v][____________________]`

## Passo 4 - Codigo

```python
relatorio = {}
for venda in vendas:
    v = venda[____________________]
    if v ____________________ relatorio:
        relatorio[v] = {____________________: ____________________, ____________________: ____________________}
    relatorio[v][____________________] += ____________________
    relatorio[v][____________________] += venda[____________________]
```

## Verificacao

`relatorio["Lucas"]` deve exibir `{'qtd': 3, 'faturamento': 3652.5}`.
