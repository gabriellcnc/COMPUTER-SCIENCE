"""Aula 12 - Problema 2.

Lista de dicionarios -> dicionario de dicionarios: acumular por entidade.
Os alunos devem completar a implementacao abaixo.
"""

vendas = [
    {"vendedor": "Lucas", "produto": "Notebook", "valor": 3500.00},
    {"vendedor": "Maria", "produto": "Mouse", "valor": 80.00},
    {"vendedor": "Lucas", "produto": "Teclado", "valor": 150.00},
    {"vendedor": "Maria", "produto": "Monitor", "valor": 900.00},
    {"vendedor": "Pedro", "produto": "Notebook", "valor": 3500.00},
    {"vendedor": "Lucas", "produto": "Caneta", "valor": 2.50},
    {"vendedor": "Maria", "produto": "Caderno", "valor": 12.90},
    {"vendedor": "Pedro", "produto": "Mouse", "valor": 80.00},
]

relatorio = {}

# TODO:
# 1. Percorra a lista vendas.
# 2. Extraia o nome do vendedor.
# 3. Se o vendedor nao existir no relatorio, inicialize com qtd 0 e faturamento 0.0.
# 4. Atualize qtd e faturamento.
