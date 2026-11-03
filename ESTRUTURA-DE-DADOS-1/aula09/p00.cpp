//EXEMPLO 1 DE PONTEIROS
#include <iostream>

using namespace std;

int main(){

    int a  = 10; //Variavel do tipo int 
    int *p;      // Ponteiro para um int

    p = &a; //p recebe o end. mem. de A

    cout << &a << endl; // end. memo de A
    cout << p << endl; // end. mem armazenado no ponteiro - end. de quem o ponteiro aponta
    cout << *p << endl; // valor apontado por P

    a = 20;     
    cout << p << endl;
    cout << *p << endl; // valor apontado por P

    int b = *p/4;
    cout << b << endl;

    return 0;
}