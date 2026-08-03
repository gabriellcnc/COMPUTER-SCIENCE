"""Aula 12 - Problema 5.

Dicionario de listas de dicionarios: tres niveis.
Os alunos devem completar a implementacao abaixo.
"""

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

# TODO:
# 1. Exiba apenas os itens disponiveis por categoria.
# 2. Calcule o preco medio dos itens disponiveis por categoria.
