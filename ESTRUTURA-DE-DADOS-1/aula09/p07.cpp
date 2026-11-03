/*
Exemplo de alocação estática de memória (uso do static)

diferente da alocação automática, a alocação estática 
o endereço de memória da variável é estatico e o valor ali
contido se mantem, mesmo em funções diferentes
*/

#include <iostream>

using namespace std;

void foo(){
    //diferente do exemplo p06.cpp
    static int n=0; //Alocação estatica
    n++;
    cout <<&n << " " << n << endl;
}

int main(){
    foo();
    foo();
    foo();
    return 0;
}