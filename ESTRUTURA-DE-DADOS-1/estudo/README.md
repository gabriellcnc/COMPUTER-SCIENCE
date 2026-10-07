# Estudos — Estrutura de Dados 1

Material organizado a partir dos conteúdos das aulas de C++ de Estrutura de Dados 1.

## Ordem recomendada de estudo

1. [Fundamentos de C++](01_fundamentos_cpp.md)
2. [Vetores](02_vetores.md)
3. [Matrizes](03_matrizes.md)
4. [Funções](04_funcoes.md)
5. [Passagem por referência](05_passagem_por_referencia.md)
6. [Templates](06_templates.md)
7. [Bubble Sort](07_bubble_sort.md)
8. [Selection Sort](08_selection_sort.md)
9. [Insertion Sort](09_insertion_sort.md)
10. [std::sort](10_std_sort.md)
11. [Structs](11_structs.md)
12. [Comparadores e ordenação de structs](12_comparadores_structs.md)
13. [Exercícios integradores](13_exercicios_integradores.md)
14. [Revisão rápida](14_revisao_rapida.md)

## Como usar esta pasta

Para cada assunto:

1. Leia o resumo.
2. Digite os exemplos sem copiar e colar.
3. Tente prever a saída antes de executar.
4. Refaça os exercícios resolvidos sem olhar a solução.
5. Faça os exercícios propostos no final.

## Compilando um arquivo C++

```bash
g++ programa.cpp -o programa
./programa
```

No Windows com MinGW:

```bash
g++ programa.cpp -o programa.exe
programa.exe
```

## Exercício resolvido de aquecimento

**Problema:** ler 5 números e mostrar a soma.

```cpp
#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    int vet[N];
    int soma = 0;

    for (int i = 0; i < N; i++) {
        cin >> vet[i];
        soma += vet[i];
    }

    cout << "Soma: " << soma << endl;
    return 0;
}
```

**Raciocínio:** o `for` percorre os índices `0` até `4`; `soma` começa em zero e acumula cada elemento.
