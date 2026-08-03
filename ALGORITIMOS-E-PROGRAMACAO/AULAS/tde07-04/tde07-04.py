# Lista de tarefas
tarefas = [
            "planejar",
            "criar",
            "revisar",
            "publicar",
            "analisar"
           ]

print("=== SISTEMA DE CONTROLE DE TAREFAS ===")

# Percorer lista
for tarefa in tarefas:
    print("=" * 40)
    print(f"TAREFA ATUAL: {tarefa}")

    # Entrada do usuário
    concluida = input("A tarefa foi concluída? (s/n): ")

    # Verificação
    if concluida == "s":
        print("Tarefa concluída com sucesso.")
    else:
        # Verificar atraso
        atrasada = input("A tarefa está atrasada? (s/n): ")

        if atrasada == "s":
            print("A tarefa está atrasada. Por favor, revise o cronograma.")
            break # Interrompe o loop "for" para impedir progressão.
        else:
            print("A tarefa está em pendente. Conclua dentro do prazo!")
            
            # Impedir progressão
            print(f"Você não pode avançar para a próxima tarefa até concluir a tarefa '{tarefa}'.")

            break # Interrompe o loop "for" para impedir progressão.

else: 
 # Se todas as tarefas forem concluídas, exibe mensagem de sucesso.
 print("=" * 40)
 print(f"Todas as tarefas foram concluídas com sucesso!")
 print("=" * 40)




