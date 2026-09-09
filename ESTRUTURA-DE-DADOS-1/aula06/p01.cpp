// Segundo exemplo de structs - Valores inseridos na declaração
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
    //ciclano.matricula = 214143;
    //ciclano.nome = "Gabriel Cenci";
    //ciclano.nota = 10.00;

    ciclano = {214143, "Gabriel Vitali Cenci", 9.7};

    // Exibindo as informações
    cout << "Matricula: " << ciclano.matricula << endl;
    cout << "Nome: " << ciclano.nome << endl;
    cout << "Nota: " << ciclano.nota << endl << endl;




    return 0;
}