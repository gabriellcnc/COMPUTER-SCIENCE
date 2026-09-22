# Fundamentos de C++

## Estrutura básica

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Ola, mundo!" << endl;
    return 0;
}
```

- `#include <iostream>` habilita `cin` e `cout`.
- `main()` é o ponto inicial do programa.
- `return 0` indica término normal.

## Tipos comuns

```cpp
int idade = 20;
float altura = 1.75f;
double media = 8.75;
char letra = 'A';
string nome = "Gabriel";
bool ativo = true;
```

## Entrada e saída

```cpp
int idade;
cout << "Idade: ";
cin >> idade;
cout << "Voce tem " << idade << " anos.\n";
```

Para texto com espaços:

```cpp
string nome;
getline(cin, nome);
```

## Condicionais

```cpp
if (nota >= 7) {
    cout << "Aprovado";
} else {
    cout << "Reprovado";
}
```

Operadores importantes: `==`, `!=`, `<`, `>`, `<=`, `>=`, `&&`, `||`, `!`.

## Laços

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << " ";
}
```

```cpp
int i = 0;
while (i < 5) {
    cout << i << " ";
    i++;
}
```

## Exercício resolvido

**Problema:** leia um número e informe se ele está entre 10 e 20, sem incluir os extremos.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n > 10 && n < 20) {
        cout << "Esta no intervalo" << endl;
    } else {
        cout << "Fora do intervalo" << endl;
    }

    return 0;
}
```

**Raciocínio:** as duas condições precisam ser verdadeiras, portanto usamos `&&`.

## Exercícios para praticar

1. Leia dois números e mostre o maior.
2. Leia uma nota e classifique em aprovado/reprovado.
3. Mostre os números de 10 até 1 usando `for`.
