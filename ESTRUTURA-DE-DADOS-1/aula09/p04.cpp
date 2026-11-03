//PONTEIROS PARA STRUCT

#include <iostream>

using namespace std;

struct aluno{
    int matricula;
    string nome;
};

int main(){

    aluno a = {909090, "Rafael Camara"};
    aluno *p = &a;

    cout << a.matricula << endl; //Acesso direto

    /*'->' significa que estamos obtendo o valor 
    substitui o * que vimos anteriormente.
    Isso vale somente para struct
    */
    cout << p->matricula << endl; //Acesso indireto (via ponteiro)

    p->nome = "Max Verstapen"; //Alteramos acessando pelo ponteiro

    cout <<  a.nome << endl; //Acesso direto

    return 0;
}