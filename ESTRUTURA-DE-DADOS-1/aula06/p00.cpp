// Primeiro exemplo utilizando structs;
#include <iostream>
using namespace std;

struct aluno{
    int matricula;
    string nome;
    float nota;
};

int main(){
    aluno ciclano, fulano; // Declara as variáveis do tipo 'aluno'

    // Inserir as informações
    ciclano.matricula = 214143;
    ciclano.nome = "Gabriel Cenci";
    ciclano.nota = 10.00;



    // Exibindo as informações
    cout << "Matricula: " << ciclano.matricula << endl;
    cout << "Nome: " << ciclano.nome << endl;
    cout << "Nota: " << ciclano.nota << endl << endl;
    
    // Iserção de dados via Terminal 
    cout << "Digite seu nome completo, sua matricula e sua nota:" << endl;
    getline(cin,fulano.nome);
    cin >> fulano.matricula;
    cin >> fulano.nota;

    cout << "Matricula: " << fulano.matricula << endl;
    cout << "Nome: " << fulano.nome << endl;
    cout << "Nota: " << fulano.nota << endl;


    return 0;
}

