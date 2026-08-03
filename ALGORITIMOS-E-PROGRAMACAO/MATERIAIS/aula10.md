# =============================================================================
# Aula 10: Dicionários
# =============================================================================

# -----------------------------------------------------------------------------
# DEMO 1 — Por que precisamos de dicionários?
# -----------------------------------------------------------------------------

# Com lista: acesso por índice — o código não explica o que cada posição representa
aluno_lista = ["Maria", "2024001", "Ciência da Computação", 8.5]
print(aluno_lista[3])   # 8.5 — mas o que é o índice 3? Exige ler a definição inteira

# Com dicionário: cada dado recebe um rótulo que explica seu significado
aluno = {
    "nome": "Maria",
    "matricula": "2024001",
    "curso": "Ciência da Computação",
    "media": 8.5
}
print(aluno["media"])   # 8.5 — a chave torna o código autoexplicativo

# Dicionário = estrutura chave → valor; as chaves devem ser únicas e imutáveis.
# Equivalentes em outras linguagens: HashMap (Java), unordered_map (C++),
# object / Map (JavaScript), associative array (PHP).

# -----------------------------------------------------------------------------
# DEMO 2 — Formas de criar dicionários
# -----------------------------------------------------------------------------

# Literal com chaves {}
produto = {
    "nome": "Notebook",
    "preco": 3500.00,
    "estoque": 15,
    "disponivel": True
}
print(produto)

# Dicionário vazio — útil quando os pares serão inseridos dinamicamente
configuracoes = {}

# Criando com a função dict() — útil para chaves que são identificadores simples
cores = dict(vermelho="#FF0000", verde="#00FF00", azul="#0000FF")
print(cores)

# Regras para chaves: devem ser de tipo imutável (str, int, float, tuple).
# Tipo mais usado e legível: str.
# Definir a mesma chave duas vezes sobrescreve o valor anterior:
demo = {"a": 1, "a": 2}
print(demo)   # {"a": 2} — a primeira definição foi descartada

# -----------------------------------------------------------------------------
# DEMO 3 — Acesso por chave e o perigo do KeyError
# -----------------------------------------------------------------------------

aluno = {"nome": "Maria", "media": 8.5, "curso": "BCC"}

# Acesso por colchetes — rápido (O(1)), mas lança KeyError se a chave não existir
print(aluno["nome"])     # Maria
print(aluno["media"])    # 8.5

# Chave inexistente → KeyError — interrompe a execução
# print(aluno["idade"])  # KeyError: 'idade' — descomente para demonstrar

# .get(chave) — retorna None se a chave não existir; nunca lança KeyError
print(aluno.get("idade"))           # None
print(aluno.get("idade", 0))        # 0 — valor padrão definido pelo programador
print(aluno.get("media", 0.0))      # 8.5 — chave existe, retorna o valor normalmente

# Regra prática:
#   []      → quando tenho certeza que a chave existe (ex: dados já validados)
#   .get()  → quando a chave pode estar ausente (ex: dicionário construído dinamicamente)

# -----------------------------------------------------------------------------
# DEMO 4 — Verificar existência com `in`
# -----------------------------------------------------------------------------

config = {"tema": "escuro", "fonte": 14}

print("tema" in config)        # True
print("idioma" in config)      # False
print("idioma" not in config)  # True

# Uso típico: verificar antes de acessar
chave = "idioma"
if chave in config:
    print(config[chave])
else:
    print(f"Configuração '{chave}' não encontrada")

# .get() já incorpora essa verificação internamente.
# Use `in` quando precisar apenas checar existência sem acessar o valor.

# -----------------------------------------------------------------------------
# DEMO 5 — Adicionar, modificar e remover pares
# -----------------------------------------------------------------------------

aluno = {"nome": "Maria", "media": 8.5, "curso": "BCC"}
print("Inicial:", aluno)

# Adicionar nova chave — mesma sintaxe de atribuição
aluno["matricula"] = "2024001"
print("Após adicionar matrícula:", aluno)

# Modificar valor existente — Python decide automaticamente se é inserção ou atualização
aluno["media"] = 9.0
print("Após atualizar média:", aluno)

# del — remove o par; lança KeyError se a chave não existir
del aluno["curso"]
print("Após del 'curso':", aluno)

# pop(chave) — remove e RETORNA o valor; permite valor padrão para chave ausente
matricula = aluno.pop("matricula")
print(f"Matrícula removida: {matricula}")
print("Após pop():", aluno)

# pop() com valor padrão — evita KeyError
cargo = aluno.pop("cargo", "não definido")
print(f"Cargo: {cargo}")   # "não definido"

# -----------------------------------------------------------------------------
# DEMO 6 — Iterando sobre dicionários
# -----------------------------------------------------------------------------

produto = {"nome": "Notebook", "preco": 3500.0, "estoque": 15}

# Iteração padrão: percorre as chaves
print("=== Chaves (for direto) ===")
for chave in produto:
    print(f"  {chave}")

# .keys() — explícito e auto-documentado; resultado idêntico ao for direto
print("\n=== .keys() ===")
for chave in produto.keys():
    print(f"  {chave}")

# .values() — quando só os valores importam
print("\n=== .values() ===")
for valor in produto.values():
    print(f"  {valor}")

# .items() — tuplas (chave, valor); o método mais usado em iterações práticas
print("\n=== .items() ===")
for chave, valor in produto.items():
    print(f"  {chave}: {valor}")

# Observação: desde Python 3.7, a ordem de inserção é garantida.

# -----------------------------------------------------------------------------
# DEMO 7 — Métodos úteis: update(), len(), clear()
# -----------------------------------------------------------------------------

config = {"tema": "escuro", "idioma": "pt-BR", "fonte": 14}
print("Inicial:", config)

# .update() — mescla outro dicionário; chaves já existentes são sobrescritas
config.update({"fonte": 16, "zoom": 100})
print("Após update:", config)
# {"tema": "escuro", "idioma": "pt-BR", "fonte": 16, "zoom": 100}

# len() — número de pares chave-valor (não o total de caracteres ou valores)
print(f"Pares no dicionário: {len(config)}")   # 4

# Cópia rasa: dict() ou .copy()
backup = dict(config)   # equivalente a config.copy()
config.clear()          # remove todos os pares
print("Após clear:", config)   # {}
print("Backup:", backup)       # intacto — clear() não afeta cópias independentes

# -----------------------------------------------------------------------------
# DEMO 8 — Contagem de frequência: padrão if/else e padrão .get()
# -----------------------------------------------------------------------------

texto = "abracadabra"

# Padrão clássico com if/else — explícito e didático
frequencia = {}
for letra in texto:
    if letra in frequencia:
        frequencia[letra] += 1
    else:
        frequencia[letra] = 1

print("if/else:", frequencia)
# {'a': 5, 'b': 2, 'r': 2, 'c': 1, 'd': 1}

# Padrão compacto com .get() — equivalente, porém mais idiomático em Python
frequencia2 = {}
for letra in texto:
    frequencia2[letra] = frequencia2.get(letra, 0) + 1

print(".get():", frequencia2)   # mesmo resultado

# Raciocínio: .get(letra, 0) retorna 0 quando a letra ainda não está no dicionário.
# Somamos 1 e reatribuímos — na primeira ocorrência de cada letra: 0 + 1 = 1.

# -----------------------------------------------------------------------------
# DEMO 9 — Programa completo: boletim de turma
# -----------------------------------------------------------------------------

# Lista de dicionários — cada aluno é um registro independente
turma = [
    {"nome": "Ana",     "nota": 8.5},
    {"nome": "Bruno",   "nota": 4.0},
    {"nome": "Carlos",  "nota": 7.0},
    {"nome": "Diana",   "nota": 9.5},
    {"nome": "Eduardo", "nota": 3.5},
    {"nome": "Flávia",  "nota": 6.0},
]

# Acumulação com for: somar notas e separar aprovados/reprovados
total_notas = 0
aprovados   = []
reprovados  = []

for aluno in turma:
    total_notas += aluno["nota"]
    if aluno["nota"] >= 5.0:
        aprovados.append(aluno["nome"])
    else:
        reprovados.append(aluno["nome"])

media = total_notas / len(turma)

# Busca do melhor e pior aluno: inicializa com o primeiro elemento
melhor_nome = turma[0]["nome"]
melhor_nota = turma[0]["nota"]
pior_nome   = turma[0]["nome"]
pior_nota   = turma[0]["nota"]

for aluno in turma:
    if aluno["nota"] > melhor_nota:
        melhor_nota = aluno["nota"]
        melhor_nome = aluno["nome"]
    if aluno["nota"] < pior_nota:
        pior_nota = aluno["nota"]
        pior_nome = aluno["nome"]

print(f"Turma com {len(turma)} alunos")
print(f"Média geral : {media:.1f}")
print(f"Aprovados   : {', '.join(aprovados)}")
print(f"Reprovados  : {', '.join(reprovados)}")
print(f"Maior nota  : {melhor_nome} ({melhor_nota})")
print(f"Menor nota  : {pior_nome} ({pior_nota})")

# Versão avançada com lambda (parâmetro key= — será estudado formalmente no futuro):
# melhor = max(turma, key=lambda a: a["nota"])
# pior   = min(turma, key=lambda a: a["nota"])


# =============================================================================
# SITUAÇÃO PROBLEMA 1 — Apuração de Votos em Eleição de Representante
# =============================================================================
#
# Contexto:
#   Uma turma está elegendo seu representante discente. Cada aluno escreveu
#   o nome do candidato de sua preferência em um papel. Os votos foram
#   digitados na lista abaixo. Votos nulos são identificados pela string "nulo".
#
# Tarefas:
#   1. Contabilize os votos de cada candidato, ignorando os votos nulos
#      na contagem por candidato (mas registre o total de nulos separado).
#   2. Determine o(s) vencedor(es) — quem obteve mais votos válidos.
#   3. Exiba o resultado completo: total de votos válidos, percentual de cada
#      candidato e o nome do vencedor. Mostre os candidatos em ordem
#      decrescente de votos.
#   4. Detecte empate: se dois ou mais candidatos dividirem o primeiro lugar,
#      liste todos e informe que haverá segundo turno.
#
# Dica para a tarefa 3:
#   Para ordenar um dicionário por valor decrescente:
#     sorted(contagem.items(), key=lambda par: par[1], reverse=True)
# =============================================================================

votos = [
    "Alice",  "Bruno",  "Alice", "nulo",   "Carlos", "Alice",
    "Bruno",  "nulo",   "Carlos","Bruno",  "Alice",  "Carlos",
    "Bruno",  "Alice",  "nulo",  "Bruno",  "Carlos", "Alice",
]

# Tarefa 1: contabilizar votos (excluindo nulos)
contagem = {}
total_nulos = 0

for voto in votos:
    if voto == "nulo":
        total_nulos += 1
    else:
        if voto not in contagem:
            contagem[voto] = 0
        contagem[voto] += 1

# Tarefa 2: determinar vencedor(es)
total_validos = sum(contagem.values())
max_votos = 0
for qtd in contagem.values():
    if qtd > max_votos:
        max_votos = qtd

vencedores = []
for candidato, qtd in contagem.items():
    if qtd == max_votos:
        vencedores.append(candidato)

# Tarefa 3: resultado em ordem decrescente de votos
print(f"Total de votos: {len(votos)}")
print(f"Votos válidos : {total_validos}")
print(f"Votos nulos   : {total_nulos}")
print("\nResultado (ordem decrescente):")
# Opção 1: sorted() retorna uma NOVA lista ordenada
resultado_ordenado = sorted(contagem.items(), key=lambda par: par[1], reverse=True)

# Opção 2 equivalente: .sort() ordena a lista no próprio lugar (in-place)
# resultado_ordenado = list(contagem.items())
# resultado_ordenado.sort(key=lambda par: par[1], reverse=True)

for candidato, qtd in resultado_ordenado:
    percentual = qtd / total_validos * 100
    print(f"  {candidato}: {qtd} voto(s) — {percentual:.1f}%")

# Tarefa 4: detectar empate
print()
if len(vencedores) > 1:
    print(f"Empate! Haverá segundo turno entre: {', '.join(vencedores)}.")
else:
    print(f"Vencedor: {vencedores[0]} com {max_votos} voto(s).")


# =============================================================================
# SITUAÇÃO PROBLEMA 2 — Controle de Estoque com Relatório de Vendas
# =============================================================================
#
# Contexto:
#   Uma pequena loja registrou todas as transações do dia. Cada transação
#   é um dicionário com produto, quantidade vendida e preço unitário.
#   O estoque inicial de cada produto é fornecido separadamente.
#
# Tarefas:
#   1. Calcule o total de unidades vendidas e o faturamento por produto.
#      Armazene os resultados em um dicionário no formato:
#        {"caneta": {"unidades": 25, "faturamento": 62.50}, ...}
#      Atenção: o mesmo produto pode aparecer em múltiplas transações.
#   2. Identifique o produto mais vendido (por unidades) e o de maior
#      faturamento (podem ser produtos diferentes).
#   3. Partindo do estoque inicial, calcule o estoque restante de cada produto
#      e liste os que ficaram abaixo do estoque mínimo de 5 unidades.
#   4. Exiba um relatório formatado com todas as informações acima.
#
# Dica para a tarefa 1:
#   Use .get() ou verifique a existência da chave antes de acumular —
#   o mesmo produto aparece em múltiplas linhas de transação.
# =============================================================================

transacoes = [
    {"produto": "caneta",   "quantidade": 12, "preco": 2.50},
    {"produto": "caderno",  "quantidade":  5, "preco": 15.90},
    {"produto": "caneta",   "quantidade":  8, "preco": 2.50},
    {"produto": "borracha", "quantidade": 20, "preco": 1.20},
    {"produto": "caderno",  "quantidade":  3, "preco": 15.90},
    {"produto": "caneta",   "quantidade":  5, "preco": 2.50},
    {"produto": "mochila",  "quantidade":  2, "preco": 89.90},
    {"produto": "borracha", "quantidade": 15, "preco": 1.20},
]

estoque_inicial = {
    "caneta": 50, "caderno": 15, "borracha": 40, "mochila": 5
}

# Tarefa 1: unidades vendidas e faturamento por produto
relatorio = {}
for t in transacoes:
    produto = t["produto"]
    if produto not in relatorio:
        relatorio[produto] = {"unidades": 0, "faturamento": 0.0}
    relatorio[produto]["unidades"]    += t["quantidade"]
    relatorio[produto]["faturamento"] += t["quantidade"] * t["preco"]

# Tarefa 2: produto mais vendido e de maior faturamento
mais_vendido   = None
maior_unidades = 0
maior_fat_nome = None
maior_fat      = 0.0

for produto, dados in relatorio.items():
    if dados["unidades"] > maior_unidades:
        maior_unidades = dados["unidades"]
        mais_vendido   = produto
    if dados["faturamento"] > maior_fat:
        maior_fat      = dados["faturamento"]
        maior_fat_nome = produto

# Tarefa 3: estoque restante e alertas de mínimo
ESTOQUE_MINIMO = 5
estoque_restante = {}
abaixo_minimo    = []

for produto, inicial in estoque_inicial.items():
    if produto in relatorio:
        vendidas = relatorio[produto]["unidades"]
    else:
        vendidas = 0
    restante = inicial - vendidas
    estoque_restante[produto] = restante
    if restante < ESTOQUE_MINIMO:
        abaixo_minimo.append(produto)

# Tarefa 4: relatório formatado
print("=" * 52)
print("RELATÓRIO DE VENDAS")
print("=" * 52)
print(f"{'Produto':<12} | {'Unidades':>8} | {'Faturamento':>12}")
print("-" * 52)
for produto, dados in relatorio.items():
    print(f"{produto:<12} | {dados['unidades']:>8} | R$ {dados['faturamento']:>9.2f}")
print("-" * 52)
print(f"\nMais vendido (unidades) : {mais_vendido} ({maior_unidades} un.)")
print(f"Maior faturamento       : {maior_fat_nome} (R$ {maior_fat:.2f})")

print("\nEstoque restante:")
for produto, qtd in estoque_restante.items():
    alerta = "  *** ABAIXO DO MÍNIMO ***" if produto in abaixo_minimo else ""
    print(f"  {produto:<12}: {qtd:>3} un.{alerta}")

if abaixo_minimo:
    print(f"\nALERTA: repor estoque de: {', '.join(abaixo_minimo)}.")
print("=" * 52)