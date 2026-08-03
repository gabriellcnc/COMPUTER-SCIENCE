# =============================================================================
# Aula 11: Tuplas e Conjuntos
# =============================================================================

# -----------------------------------------------------------------------------
# DEMO 1 — Tupla vs. lista: imutabilidade na prática
# -----------------------------------------------------------------------------

# Lista — mutável: podemos alterar, adicionar e remover elementos
frutas_lista = ["maçã", "banana", "laranja"]
frutas_lista[0] = "uva"          # OK
frutas_lista.append("manga")     # OK
print(frutas_lista)   # ['uva', 'banana', 'laranja', 'manga']

# Tupla — imutável: a estrutura é "congelada" na criação
frutas_tupla = ("maçã", "banana", "laranja")
# frutas_tupla[0] = "uva"   # TypeError — descomente para demonstrar o erro

# Por que imutabilidade importa?
#   - Protege dados que não devem mudar (configurações, coordenadas, constantes)
#   - Indica ao leitor do código que aquele dado é "fixo por natureza"
#   - Permite usar a tupla como chave de dicionário (listas não podem)

# -----------------------------------------------------------------------------
# DEMO 2 — Criando tuplas
# -----------------------------------------------------------------------------

coordenada   = (10.5, -23.4)        # par de coordenadas geográficas
rgb          = (255, 128, 0)         # cor laranja em RGB
vazia        = ()                    # tupla vazia
um_elemento  = (42,)                 # a vírgula é obrigatória para 1 elemento!

# Armadilha comum: (42) NÃO é tupla — é apenas o número 42 com parênteses
nao_e_tupla = (42)
e_tupla     = (42,)
print(type(nao_e_tupla))  # <class 'int'>
print(type(e_tupla))      # <class 'tuple'>

# Empacotamento implícito — Python cria a tupla sem os parênteses
ponto = 3, 7
print(ponto)         # (3, 7)
print(type(ponto))   # <class 'tuple'>

# -----------------------------------------------------------------------------
# DEMO 3 — Acessando elementos: indexação e fatiamento
# -----------------------------------------------------------------------------

cores = ("vermelho", "verde", "azul")

print(cores[0])      # vermelho     — primeiro elemento
print(cores[-1])     # azul         — último elemento
print(cores[1:])     # ('verde', 'azul') — fatiamento idêntico ao de listas
print(len(cores))    # 3

# Iteração — funciona igual às listas
for cor in cores:
    print(f"  cor: {cor}")

# -----------------------------------------------------------------------------
# DEMO 4 — Desempacotamento de tupla
# -----------------------------------------------------------------------------

# Atribuição de múltiplos valores em uma única linha
ponto = (3, 7)
x, y = ponto
print(f"x={x}, y={y}")   # x=3, y=7

# Caso de uso clássico: .items() de dicionário retorna tuplas (chave, valor)
aluno = {"nome": "João", "nota": 9.5}
for chave, valor in aluno.items():
    print(f"  {chave} → {valor}")

# enumerate() também retorna tuplas (índice, elemento)
linguagens = ["Python", "Java", "C++"]
for indice, lang in enumerate(linguagens):
    print(f"  {indice}: {lang}")

# Desempacotamento parcial com * (captura o "resto" numa lista)
primeiro, *meio, ultimo = (10, 20, 30, 40, 50)
print(f"primeiro={primeiro}, meio={meio}, ultimo={ultimo}")
# primeiro=10, meio=[20, 30, 40], ultimo=50

# -----------------------------------------------------------------------------
# DEMO 5 — Tuplas como chaves de dicionário
# -----------------------------------------------------------------------------

# Listas não podem ser chaves — são mutáveis, portanto não "hasheáveis"
# dicionario[["lat", "lon"]] = "cidade"  # TypeError: unhashable type: 'list'

# Tuplas são imutáveis, então funcionam como chaves
mapa_cidades = {
    (-23.55, -46.63): "São Paulo",
    (-22.91, -43.17): "Rio de Janeiro",
    (-19.92, -43.94): "Belo Horizonte",
}

print(mapa_cidades[(-23.55, -46.63)])   # São Paulo

# Percorrendo: desempacotamos a chave (tupla) e o valor em uma linha
for (lat, lon), cidade in mapa_cidades.items():
    print(f"  {cidade}: lat={lat}, lon={lon}")

# -----------------------------------------------------------------------------
# DEMO 6 — Criando conjuntos e eliminando duplicatas
# -----------------------------------------------------------------------------

# Conjunto literal — duplicatas são ignoradas automaticamente
linguagens = {"Python", "Java", "C++", "Python", "Java"}
print(linguagens)   # {'Python', 'Java', 'C++'} — apenas elementos únicos

# ATENÇÃO: {} cria dicionário vazio, NÃO conjunto vazio
vazio_dict = {}
vazio_set  = set()
print(type(vazio_dict))   # <class 'dict'>
print(type(vazio_set))    # <class 'set'>

# A partir de uma lista — forma prática de remover duplicatas
notas_brutas = [8.0, 7.5, 8.0, 9.0, 7.5, 6.0]
notas_unicas = set(notas_brutas)
print(notas_unicas)   # {8.0, 7.5, 9.0, 6.0} — ordem não garantida

# Conjuntos não têm índice — print(notas_unicas[0]) causaria TypeError
# Use-os quando importa apenas "quem está presente", não a posição

# -----------------------------------------------------------------------------
# DEMO 7 — Adicionando, removendo e verificando pertencimento
# -----------------------------------------------------------------------------

frutas = {"maçã", "banana"}

frutas.add("laranja")          # adiciona um elemento
frutas.add("banana")           # elemento já existe — conjunto não muda
print(frutas)                  # {'maçã', 'banana', 'laranja'}

frutas.remove("banana")        # remove — lança KeyError se não existir
# frutas.remove("uva")         # KeyError — descomente para demonstrar

frutas.discard("uva")          # remove sem erro se não existir — mais seguro
print(frutas)                  # {'maçã', 'laranja'}

# Verificação de pertencimento — O(1) em conjuntos (muito eficiente)
print("maçã" in frutas)        # True
print("banana" in frutas)      # False
print(len(frutas))             # 2

# Comparação: verificar pertencimento em lista é O(n) — percorre um por um
frutas_lista = ["maçã", "laranja"]
print("maçã" in frutas_lista)  # True, mas mais lento para listas grandes

# -----------------------------------------------------------------------------
# DEMO 8 — Operações de conjunto
# -----------------------------------------------------------------------------

A = {1, 2, 3, 4, 5}
B = {4, 5, 6, 7, 8}

# União — todos os elementos de A e B (sem repetição)
print("União:              ", A | B)              # {1, 2, 3, 4, 5, 6, 7, 8}
print("União (método):     ", A.union(B))         # mesmo resultado

# Interseção — apenas o que está em A E em B
print("Interseção:         ", A & B)              # {4, 5}
print("Interseção (método):", A.intersection(B))  # {4, 5}

# Diferença — o que está em A mas NÃO em B
print("Diferença A-B:      ", A - B)              # {1, 2, 3}
print("Diferença B-A:      ", B - A)              # {6, 7, 8}

# Diferença simétrica — o que está em A ou B, mas não nos dois
print("Dif. simétrica:     ", A ^ B)              # {1, 2, 3, 6, 7, 8}
print("Dif. sim. (método): ", A.symmetric_difference(B))

# Subconjunto e superconjunto
C = {1, 2}
print(C.issubset(A))     # True  — C ⊆ A (todo elemento de C está em A)
print(A.issuperset(C))   # True  — A ⊇ C
print(A.isdisjoint(B))   # False — compartilham elementos {4, 5}
print(C.isdisjoint(B))   # True  — C e B não têm elementos em comum

# -----------------------------------------------------------------------------
# DEMO 9 — Programa completo: comparando entregas de TPs
# -----------------------------------------------------------------------------

# Alunos que entregaram cada TP (com duplicatas por falha de sistema)
entregaram_tp1 = ["Ana", "Bruno", "Carlos", "Diana", "Ana"]
entregaram_tp2 = ["Bruno", "Diana", "Eduardo", "Carlos"]

set_tp1 = set(entregaram_tp1)   # {'Ana', 'Bruno', 'Carlos', 'Diana'}
set_tp2 = set(entregaram_tp2)   # {'Bruno', 'Carlos', 'Diana', 'Eduardo'}

print("Entregaram ambos os TPs:    ", set_tp1 & set_tp2)
# {'Bruno', 'Carlos', 'Diana'}

print("Entregaram apenas o TP1:    ", set_tp1 - set_tp2)
# {'Ana'}

print("Entregaram apenas o TP2:    ", set_tp2 - set_tp1)
# {'Eduardo'}

print("Entregaram pelo menos um TP:", set_tp1 | set_tp2)
# {'Ana', 'Bruno', 'Carlos', 'Diana', 'Eduardo'}

print("Nenhum entregou os dois:    ", set_tp1 ^ set_tp2)
# {'Ana', 'Eduardo'} — entregaram exatamente um dos TPs


# =============================================================================
# SITUAÇÃO PROBLEMA 1 — Controle de Presença e Aprovação por Frequência
# =============================================================================
#
# Contexto:
#   Uma disciplina realiza chamada em cada aula. Cada chamada é registrada
#   como um conjunto de alunos presentes naquele dia. A frequência mínima
#   para aprovação é de 75% das aulas realizadas.
#   Os dados de cada aluno também incluem matrícula e nome, armazenados
#   como tuplas para garantir que não sejam modificados acidentalmente.
#
# Tarefas:
#   1. A partir das chamadas diárias, determine quantas aulas cada aluno
#      frequentou. Use conjuntos para identificar quais alunos ao menos
#      uma vez estiveram presentes.
#   2. Calcule o percentual de frequência de cada aluno e classifique-os
#      como "Aprovado por frequência" ou "Reprovado por falta".
#   3. Liste os alunos que nunca compareceram a nenhuma aula.
#   4. Exiba o relatório ordenado por frequência decrescente, mostrando
#      matrícula, nome, aulas presentes e percentual.
# =============================================================================

# Cada aluno é uma tupla (matricula, nome) — imutável e pode ser chave de dicionário
alunos = [
    ("2024001", "Ana"),
    ("2024002", "Bruno"),
    ("2024003", "Carlos"),
    ("2024004", "Diana"),
    ("2024005", "Eduardo"),
    ("2024006", "Flávia"),
]

# Chamadas por aula — cada conjunto representa os presentes naquele dia
chamadas = [
    {"Ana", "Bruno", "Carlos", "Diana"},
    {"Ana", "Carlos", "Eduardo", "Flávia"},
    {"Ana", "Bruno", "Diana", "Flávia"},
    {"Bruno", "Carlos", "Diana"},
    {"Ana", "Carlos", "Eduardo"},
    {"Ana", "Bruno", "Diana", "Flávia"},
    {"Ana", "Carlos", "Diana", "Eduardo"},
    {"Bruno", "Diana", "Flávia"},
]

TOTAL_AULAS = len(chamadas)
MINIMO_FREQUENCIA = 0.75

# Tarefa 1: contar presenças por nome usando dicionário com matrícula como chave
# A matrícula (str imutável) identifica o aluno; usamos o nome para buscar nas chamadas
presencas = {}   # matrícula → quantidade de presenças

for matricula, nome in alunos:
    contagem = 0
    for chamada in chamadas:
        if nome in chamada:
            contagem += 1
    presencas[matricula] = contagem

# Tarefa 2: classificar por frequência
resultado = []
for matricula, nome in alunos:
    qtd = presencas[matricula]
    percentual = qtd / TOTAL_AULAS
    if percentual >= MINIMO_FREQUENCIA:
        situacao = "Aprovado por frequência"
    else:
        situacao = "Reprovado por falta"
    resultado.append((matricula, nome, qtd, percentual, situacao))

# Tarefa 3: alunos que nunca compareceram
todos_presentes = set()
for chamada in chamadas:
    todos_presentes = todos_presentes | chamada   # união acumulada

ausentes_sempre = []
for matricula, nome in alunos:
    if nome not in todos_presentes:
        ausentes_sempre.append((matricula, nome))

# Tarefa 4: relatório ordenado por frequência decrescente
print("=" * 62)
print("RELATÓRIO DE FREQUÊNCIA")
print(f"Total de aulas: {TOTAL_AULAS}  |  Mínimo: {MINIMO_FREQUENCIA*100:.0f}%")
print("=" * 62)
print(f"{'Matrícula':<10} {'Nome':<12} {'Presenças':>9} {'Frequência':>11}  Situação")
print("-" * 62)

# Opção 1: sorted() retorna uma NOVA lista ordenada
resultado_ordenado = sorted(resultado, key=lambda r: r[3], reverse=True)

# Opção 2 equivalente: .sort() ordena no próprio lugar
# resultado_ordenado = list(resultado)
# resultado_ordenado.sort(key=lambda r: r[3], reverse=True)

for matricula, nome, qtd, percentual, situacao in resultado_ordenado:
    print(f"{matricula:<10} {nome:<12} {qtd:>5}/{TOTAL_AULAS:<3}  {percentual*100:>7.1f}%  {situacao}")

if ausentes_sempre:
    print("\nAlunos sem nenhuma presença registrada:")
    for mat, nome in ausentes_sempre:
        print(f"  [{mat}] {nome}")
else:
    print("\nTodos os alunos compareceram ao menos uma vez.")
print("=" * 62)


# =============================================================================
# SITUAÇÃO PROBLEMA 2 — Análise de Preferências em Pesquisa de Disciplinas
# =============================================================================
#
# Contexto:
#   Uma pesquisa pediu a cada aluno que indicasse quais disciplinas optativas
#   deseja cursar no próximo semestre. As respostas foram coletadas como listas
#   (podendo ter repetições por erro de formulário). Cada aluno é identificado
#   por uma tupla (matricula, nome).
#
# Tarefas:
#   1. Normalize as respostas: elimine as disciplinas duplicadas por aluno
#      usando conjuntos, e garanta que os nomes das disciplinas estejam em
#      minúsculas sem espaços extras (use .strip().lower()).
#   2. Calcule quantos alunos escolheram cada disciplina e ordene
#      as disciplinas pela popularidade (maior para menor).
#   3. Identifique as disciplinas escolhidas por TODOS os alunos
#      (interseção de todas as respostas).
#   4. Identifique alunos com gostos em comum: para cada par de alunos,
#      liste as disciplinas que ambos escolheram (interseção). Exiba apenas
#      os pares com ao menos uma disciplina em comum.
# =============================================================================

# Cada entrada: (aluno_tupla, lista_bruta_de_disciplinas)
respostas_brutas = [
    (("2024001", "Ana"),     ["IA", "redes", "IA", " Banco de Dados", "Compiladores"]),
    (("2024002", "Bruno"),   ["Redes", "banco de dados", "IA", "Redes"]),
    (("2024003", "Carlos"),  ["compiladores", "IA", "Redes", "Compiladores"]),
    (("2024004", "Diana"),   ["banco de dados", " IA", "redes", "Compiladores"]),
    (("2024005", "Eduardo"), ["IA", "banco de dados", "IA"]),
]

# Tarefa 1: normalizar respostas em conjuntos
preferencias = {}   # (matricula, nome) → set de disciplinas normalizadas

for aluno_tupla, lista in respostas_brutas:
    disciplinas_limpas = set()
    for d in lista:
        disciplinas_limpas.add(d.strip().lower())
    preferencias[aluno_tupla] = disciplinas_limpas

print("Preferências normalizadas:")
for (mat, nome), discs in preferencias.items():
    print(f"  [{mat}] {nome}: {sorted(discs)}")

# Tarefa 2: popularidade de cada disciplina
popularidade = {}
for discs in preferencias.values():
    for d in discs:
        if d not in popularidade:
            popularidade[d] = 0
        popularidade[d] += 1

print("\nPopularidade das disciplinas (maior → menor):")
# Opção 1: sorted() retorna uma NOVA lista ordenada
popularidade_ordenada = sorted(popularidade.items(), key=lambda par: par[1], reverse=True)

# Opção 2 equivalente: .sort() ordena no próprio lugar
# popularidade_ordenada = list(popularidade.items())
# popularidade_ordenada.sort(key=lambda par: par[1], reverse=True)

for disc, qtd in popularidade_ordenada:
    barra = "#" * qtd
    print(f"  {disc:<20}: {qtd} aluno(s)  {barra}")

# Tarefa 3: disciplinas escolhidas por TODOS os alunos (interseção global)
sets_lista = list(preferencias.values())
comuns_a_todos = sets_lista[0]
for s in sets_lista[1:]:
    comuns_a_todos = comuns_a_todos & s   # interseção acumulada

print(f"\nDisciplinas escolhidas por TODOS: ", comuns_a_todos if comuns_a_todos else "(nenhuma)")

# Tarefa 4: pares de alunos com disciplinas em comum
print("\nPares de alunos com interesses em comum:")
alunos_lista = list(preferencias.keys())

encontrou_par = False
for i in range(len(alunos_lista)):
    for j in range(i + 1, len(alunos_lista)):
        aluno_a = alunos_lista[i]
        aluno_b = alunos_lista[j]
        em_comum = preferencias[aluno_a] & preferencias[aluno_b]
        if em_comum:
            print(f"  {aluno_a[1]} & {aluno_b[1]}: {sorted(em_comum)}")
            encontrou_par = True

if not encontrou_par:
    print("  Nenhum par de alunos compartilha disciplinas.")