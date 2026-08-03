media = 9.7

# Apresentar o conceito do aluno baseado na nota média
# A: 9.0 - 10.0
# B: 8.0 - 8.9
# C: 7.0 - 7.9
# D: 6.0 - 6.9
# F: 0.0 - 5.9

if media >= 9.0:
    conceito = "A"
elif media >= 8.0:
    conceito = "B"
elif media >= 7.0:
    conceito = "C"
elif media >= 6.0:
    conceito = "D"
else:
    conceito = "F"

print(f"Media: {media}", f"conceito: {conceito}")