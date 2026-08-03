# =============================================================================
# Aula 09: Introdução a Listas
# =============================================================================

# -----------------------------------------------------------------------------
# DEMO 1 — Por que precisamos de listas?
# -----------------------------------------------------------------------------

# Sem lista: uma variável por nota — inviável para 30 alunos
nota_aluno1 = 8.5
nota_aluno2 = 6.0
nota_aluno3 = 9.5
# ... e assim até nota_aluno30 — imagine calcular a média disso!

# Com lista: todos os dados em uma única estrutura
notas_turma = [8.5, 6.0, 9.5, 4.0, 7.5, 8.0, 5.5, 9.0, 6.5, 7.0]
print(notas_turma)
print(f"Temos {len(notas_turma)} notas cadastradas")

# -----------------------------------------------------------------------------
# DEMO 2 — Indexação: acessando elementos por posição
# -----------------------------------------------------------------------------

filmes = ["Matrix", "Inception", "Interstellar", "Dune", "Arrival"]
#índice:      0           1              2            3        4

# Acesso por índice positivo
print(filmes[0])   # Matrix
print(filmes[2])   # Interstellar

# Índices negativos contam a partir do final
print(filmes[-1])  # Arrival  — último
print(filmes[-2])  # Dune     — penúltimo

# O que acontece com um índice fora do intervalo?
# print(filmes[10])  # IndexError — descomente para demonstrar o erro

# -----------------------------------------------------------------------------
# DEMO 3 — len() e a relação com os índices válidos
# -----------------------------------------------------------------------------

filmes = ["Matrix", "Inception", "Interstellar", "Dune", "Arrival"]

tamanho = len(filmes)
print(f"A lista tem {tamanho} elementos")
print(f"Índices válidos: 0 a {tamanho - 1}")

# O último índice válido é sempre len(lista) - 1
ultimo = filmes[tamanho - 1]
print(f"Último filme: {ultimo}")   # equivalente a filmes[-1]

# -----------------------------------------------------------------------------
# DEMO 4 — Fatiamento (slicing): extraindo partes da lista
# -----------------------------------------------------------------------------

notas = [4.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0, 8.5, 9.0, 9.5]
#índice:   0    1    2    3    4    5    6    7    8    9

# lista[inicio:fim] — fim é EXCLUSIVO
print(notas[0:3])    # [4.0, 5.5, 6.0]      — primeiros 3
print(notas[7:])     # [8.5, 9.0, 9.5]      — do índice 7 ao final
print(notas[:4])     # [4.0, 5.5, 6.0, 6.5] — do início até índice 3

# Com passo: lista[inicio:fim:passo]
print(notas[::2])    # [4.0, 6.0, 7.0, 8.0, 9.0]  — posições pares
print(notas[::-1])   # lista invertida

# -----------------------------------------------------------------------------
# DEMO 5 — Listas são mutáveis: modificando elementos
# -----------------------------------------------------------------------------

compras = ["arroz", "feijão", "macarrão"]
print("Antes:", compras)

compras[1] = "lentilha"   # substitui o elemento no índice 1
print("Depois:", compras)

# Contraste: strings são IMUTÁVEIS
texto = "Python"
# texto[0] = "J"  # TypeError! Descomente para demonstrar a diferença.

# -----------------------------------------------------------------------------
# DEMO 6 — Métodos: construindo e editando uma lista dinamicamente
# -----------------------------------------------------------------------------

playlist = []

playlist.append("Bohemian Rhapsody")
playlist.append("Hotel California")
playlist.append("Stairway to Heaven")
print("Após appends:", playlist)

playlist.insert(0, "Back in Black")             # insere no início
playlist.insert(2, "Smells Like Teen Spirit")
print("Após inserts:", playlist)

playlist.remove("Hotel California")             # remove por valor
print("Após remove:", playlist)

removida = playlist.pop()                       # retira e retorna o último
print(f"Removida: {removida}")
print("Após pop():", playlist)

# -----------------------------------------------------------------------------
# DEMO 7 — Ordenação: sort() vs sorted()
# -----------------------------------------------------------------------------

numeros = [42, 7, 19, 3, 88, 15]

# sort() modifica a lista original (in-place)
numeros.sort()
print("Crescente:", numeros)      # [3, 7, 15, 19, 42, 88]

numeros.sort(reverse=True)
print("Decrescente:", numeros)    # [88, 42, 19, 15, 7, 3]

# sorted() retorna uma NOVA lista; a original não é alterada
original = [42, 7, 19, 3, 88, 15]
nova = sorted(original)
print("Original:", original)      # [42, 7, 19, 3, 88, 15] — intacta
print("Nova:    ", nova)          # [3, 7, 15, 19, 42, 88]

# -----------------------------------------------------------------------------
# DEMO 8 — Iteração: for simples e com índice explícito
# -----------------------------------------------------------------------------

linguagens = ["Python", "Java", "C", "JavaScript", "Rust"]

# Iteração simples: obtemos cada elemento diretamente
print("=== Linguagens ===")
for linguagem in linguagens:
    print(f"  - {linguagem}")

# Iteração com índice: facilita visualizar posição e elemento
print("\n=== Com numeração ===")
for i in range(len(linguagens)):
    linguagem = linguagens[i]
    print(f"  {i + 1}. {linguagem}")   # +1 para exibir a partir de 1

# -----------------------------------------------------------------------------
# DEMO 9 — Programa completo: análise de notas da turma
# -----------------------------------------------------------------------------

notas = [8.5, 4.0, 7.0, 9.5, 3.5, 6.0, 8.0, 5.5]

media = sum(notas) / len(notas)
maior = max(notas)
menor = min(notas)

acima_da_media = 0
for nota in notas:
    if nota >= media:
        acima_da_media += 1

print(f"Turma com {len(notas)} alunos")
print(f"Média   : {media:.1f}")
print(f"Maior   : {maior}")
print(f"Menor   : {menor}")
print(f"Acima da média: {acima_da_media} aluno(s)")


# =============================================================================
# SITUAÇÃO PROBLEMA 1 — Análise de Temperaturas com Detecção de Onda de Calor
# =============================================================================
#
# Contexto:
#   Uma estação meteorológica registrou as temperaturas diárias (em °C) de
#   uma cidade ao longo de duas semanas. O departamento de saúde quer
#   identificar períodos de risco para a população.
#
# Tarefas:
#   1. Calcule e exiba a temperatura média do período.
#   2. Identifique o dia mais quente e o mais frio, exibindo o nome do dia e
#      a temperatura.
#   3. Liste todos os dias cuja temperatura ficou acima da média, no formato:
#         "Qui (semana 1): 33.1°C"
#   4. Detecte se houve alguma "onda de calor": três ou mais dias consecutivos
#      com temperatura acima de 32°C. Se sim, informe quantos dias consecutivos
#      foram e em qual dia começou.
#
# Dica para a tarefa 4:
#   Você precisará percorrer a lista com um índice e verificar
#   temperaturas[i], temperaturas[i+1] e temperaturas[i+2] ao mesmo tempo.
#   Cuidado com o limite do índice!
# =============================================================================

temperaturas = [28.5, 31.2, 30.8, 33.1, 29.7, 27.3, 26.8,
                32.4, 35.1, 34.9, 33.7, 31.5, 29.2, 28.1]

dias = ["Seg", "Ter", "Qua", "Qui", "Sex", "Sáb", "Dom",
        "Seg", "Ter", "Qua", "Qui", "Sex", "Sáb", "Dom"]

# Tarefa 1: temperatura média
media = sum(temperaturas) / len(temperaturas)
print(f"Média do período: {media:.1f}°C")

# Tarefa 2: dia mais quente e mais frio
indice_max = 0
indice_min = 0
for i in range(len(temperaturas)):
    if temperaturas[i] > temperaturas[indice_max]:
        indice_max = i
    if temperaturas[i] < temperaturas[indice_min]:
        indice_min = i

semana_max = "semana 1" if indice_max < 7 else "semana 2"
semana_min = "semana 1" if indice_min < 7 else "semana 2"
print(f"Mais quente: {dias[indice_max]} ({semana_max}) — {temperaturas[indice_max]}°C")
print(f"Mais frio  : {dias[indice_min]} ({semana_min}) — {temperaturas[indice_min]}°C")

# Tarefa 3: dias acima da média
print("\nDias acima da média:")
for i in range(len(temperaturas)):
    if temperaturas[i] > media:
        semana = "semana 1" if i < 7 else "semana 2"
        print(f"  {dias[i]} ({semana}): {temperaturas[i]}°C")

# Tarefa 4: onda de calor — janela de 3 índices consecutivos
onda_detectada = False
for i in range(len(temperaturas) - 2):
    if (temperaturas[i] > 32.0 and
            temperaturas[i + 1] > 32.0 and
            temperaturas[i + 2] > 32.0):
        if i == 0 or temperaturas[i - 1] <= 32.0:   # início de nova sequência
            duracao = 3
            while i + duracao < len(temperaturas) and temperaturas[i + duracao] > 32.0:
                duracao += 1
            semana = "semana 1" if i < 7 else "semana 2"
            print(f"\nOnda de calor detectada! {duracao} dias consecutivos a partir de {dias[i]} ({semana}).")
            onda_detectada = True

if not onda_detectada:
    print("\nNenhuma onda de calor detectada no período.")


# =============================================================================
# SITUAÇÃO PROBLEMA 2 — Fila de Atendimento com Prioridade
# =============================================================================
#
# Contexto:
#   Uma UBS (Unidade Básica de Saúde) precisa gerenciar sua fila de
#   atendimento. Clientes comuns entram no FINAL da fila. Clientes com
#   prioridade (idosos, gestantes, pessoas com deficiência) entram logo
#   APÓS o primeiro da fila — que já está sendo atendido e não pode ser
#   deslocado.
#
# Tarefas:
#   Simule as operações abaixo NA ORDEM indicada, imprimindo o estado da fila
#   após cada uma:
#     1. "Paulo" chega e entra normalmente no final da fila.
#     2. "Dona Rosa" tem prioridade — entra logo após o primeiro.
#     3. "Carlos" (primeiro da fila) é chamado para atendimento.
#        Imprima: "Chamando: Carlos"
#     4. "Lucas" chega e entra normalmente.
#     5. "Seu Antônio" tem prioridade — entra logo após o primeiro da fila atual.
#     6. Exiba a fila final com a posição de cada pessoa (1ª, 2ª, 3ª...).
#     7. Informe quantas pessoas ainda aguardam atendimento.
#
#   Extensão:
#     Adapte o programa para simular o atendimento de TODOS os pacientes na
#     ordem correta, chamando-os um a um até a fila esvaziar.
#
# Dica:
#   Um paciente prioritário entra na posição 1 (índice 1) — não no início
#   absoluto (índice 0), pois o primeiro já está sendo atendido.
# =============================================================================

# Fila no início do dia — cada string é o nome do paciente
fila = ["Carlos", "Maria", "João", "Ana"]

# 1. Paulo entra normalmente no final
fila.append("Paulo")
print(f"[Após Paulo entrar]  : {fila}")

# 2. Dona Rosa tem prioridade — entra logo após o primeiro (índice 1)
fila.insert(1, "Dona Rosa")
print(f"[Após Dona Rosa]     : {fila}")

# 3. Carlos (primeiro) é chamado para atendimento
chamado = fila.pop(0)
print(f"Chamando: {chamado}")
print(f"[Após Carlos sair]   : {fila}")

# 4. Lucas entra normalmente
fila.append("Lucas")
print(f"[Após Lucas entrar]  : {fila}")

# 5. Seu Antônio tem prioridade — entra logo após o primeiro atual
fila.insert(1, "Seu Antônio")
print(f"[Após Seu Antônio]   : {fila}")

# 6. Fila final com posições
print("\nFila atual:")
for i in range(len(fila)):
    pessoa = fila[i]
    print(f"  {i + 1}ª: {pessoa}")

# 7. Total aguardando
print(f"\nTotal aguardando: {len(fila)} paciente(s)")

# Extensão: atender todos os pacientes na ordem
print("\n--- Extensão: atendendo todos ---")
while fila:
    chamado = fila.pop(0)
    print(f"Chamando: {chamado}")
print("Fila vazia — atendimento encerrado.")