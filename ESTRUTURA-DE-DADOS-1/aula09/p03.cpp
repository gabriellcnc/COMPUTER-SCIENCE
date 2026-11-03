#include <iostream>

using namespace std;

int main(){
    int a = 10;
    int *p = &a; //p aponta para o end. de A

    int **pp; //Declarou um ponteiro para ponteiros
   
    /*
    Atribui o end. mem. do ponteiro P ao 
    ponteiro de ponteiros PP
    */
    pp = &p;

    cout << pp   << " " //o end. de 'p' por meio do ponteiro 'pp'
         << *pp  << " " // o valor apontado por 'pp', que é o endereço de 'A' (valor do ponteiro P)
         << **pp << " " //o valor apontado duas vezes por 'pp', ou seja, o valor de 'A'
         << &pp << endl; // o end. de memoria onde esta armazenado o ponteiro para ponteiros PP

         

    return 0;
}