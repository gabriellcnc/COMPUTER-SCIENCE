#include <iostream>
#include <queue>

using namespace std;

struct pessoa{
    string nome, email;
};

int main(){
    queue<pessoa> fila;
    pessoa aux;

    /*
        A variavel aux servirá somente para coletar as informações
        vindas do teclado (leitura);
        Em cada iteração do laço de repetição, este valor mudará;
        Os dados serâo salvos na fila utilizando PUSH(AUX).
    */

    while(true){
        cout << "Digite o nome ou FIM para sair; ";
        getline(cin,aux.nome);
        if(aux.nome == "FIM"){
            cout << "Você resolveu sair, até logo!\n\n";
            break;
        }
        cout << "Informe o email: ";
        getline(cin,aux.email);
        fila.push(aux);

        cout << "T: " << fila.size() << endl;
    }

    // Remover e exibir os valores da fila
    while(!fila.empty()){
        cout << "Nome: " << fila.front().nome << endl
             << "Email: " << fila.front().email << endl
             << endl;

        fila.pop();

    }

    return 0;
};
