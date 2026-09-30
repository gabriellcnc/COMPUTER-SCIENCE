#include <iostream>
#include <stack>

using namespace std;

int main() {

    string expressao;

    getline(cin, expressao);

    stack<char> pilha;

    bool bemFormada = true;

    for (int i = 0; i < expressao.size(); i++) {

        char c = expressao[i];

        // Abre parêntese
        if (c == '(') {

            pilha.push(c);
        }

        // Abre colchete
        else if (c == '[') {

            // Não pode ter colchete dentro de parêntese
            if (!pilha.empty() && pilha.top() == '(') {
                bemFormada = false;
                break;
            }

            pilha.push(c);
        }

        // Abre chave
        else if (c == '{') {

            // Chave não pode ficar dentro de outro símbolo
            if (!pilha.empty()) {
                bemFormada = false;
                break;
            }

            pilha.push(c);
        }

        // Fecha parêntese
        else if (c == ')') {

            if (pilha.empty() || pilha.top() != '(') {
                bemFormada = false;
                break;
            }

            pilha.pop();
        }

        // Fecha colchete
        else if (c == ']') {

            if (pilha.empty() || pilha.top() != '[') {
                bemFormada = false;
                break;
            }

            pilha.pop();
        }

        // Fecha chave
        else if (c == '}') {

            if (pilha.empty() || pilha.top() != '{') {
                bemFormada = false;
                break;
            }

            pilha.pop();
        }
    }

    // Se sobrou símbolo de abertura
    if (!pilha.empty()) {
        bemFormada = false;
    }

    if (bemFormada) {
        cout << "Bem formada" << endl;
    }
    else {
        cout << "Mal formada" << endl;
    }

    return 0;
}