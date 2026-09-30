#include <iostream>
#include <stack>

using namespace std;

int converter(string texto) {

    int numero = 0;

    for (int i = 0; i < texto.size(); i++) {
        numero = numero * 10 + (texto[i] - '0');
    }

    return numero;
}

int avaliarRPN(string tokens[], int n) {

    stack<int> pilha;

    for (int i = 0; i < n; i++) {

        if (tokens[i] == "+" ||
            tokens[i] == "-" ||
            tokens[i] == "*" ||
            tokens[i] == "/") {

            int b = pilha.top();
            pilha.pop();

            int a = pilha.top();
            pilha.pop();

            if (tokens[i] == "+") {
                pilha.push(a + b);
            }

            else if (tokens[i] == "-") {
                pilha.push(a - b);
            }

            else if (tokens[i] == "*") {
                pilha.push(a * b);
            }

            else if (tokens[i] == "/") {
                pilha.push(a / b);
            }
        }

        else {
            pilha.push(converter(tokens[i]));
        }
    }

    return pilha.top();
}

int main() {

    string tokens[5] = {"2", "1", "+", "3", "*"};

    cout << avaliarRPN(tokens, 5) << endl;

    return 0;
}