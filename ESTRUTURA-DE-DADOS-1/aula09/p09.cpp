#include <iostream>

using namespace std;

int main(){

    /*
        Declaramos um ponteiro e apontamos para um espaço de 
        memória que armazenará um int    
        Neste caso a unica forma de acessar esse end. é
        via ponteiro, pois não temos um nome de variavel 
        atrelado aquele end. de mem.
    */

    int *p = new int; //Aloca
    *p = 0;
    cout << p << " " << *p << endl;
    delete p; //Desaloca

    //CUIDADO
    //Vazamento de memória
    //Se trocarmos o ponteiro, o endereço de memória fica perdido

    int a = 5;
    int *p1 = &a;

    int *p2 = new int;
    *p2 = 35;
    //*p2 = *p1
    p2 = p1;

    cout << a << " " << *p1 << " " << *p2 << endl;


    return 0;
}