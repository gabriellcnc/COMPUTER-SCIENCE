#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<string> voltar;
    stack<string> avancar;

    string atual = "";
    string comando;


    while (cin >> comando) {

        if (comando == "VISIT") {

            string url;
            cin >> url;

            if (atual != "") {
                voltar.push(atual);
            }

            atual = url;

            while (!avancar.empty()) {
                avancar.pop();
            }
        }

        else if (comando == "BACK") {

            if (voltar.empty()) {

                cout << "SEM HISTORICO" << endl;

            } else {

                avancar.push(atual);

                atual = voltar.top();

                voltar.pop();
            }
        }

        else if (comando == "FORWARD") {

            if (avancar.empty()) {

                cout << "SEM HISTORICO" << endl;

            } else {

                voltar.push(atual);

                atual = avancar.top();

                avancar.pop();
            }
        }

        else if (comando == "SHOW") {

            if (atual == "") {

                cout << "SEM HISTORICO" << endl;

            } else {

                cout << atual << endl;
            }
        }
    }

    return 0;
}