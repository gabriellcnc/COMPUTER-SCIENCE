// Alteramos o valor do ponteiro para
//alterar o valor da variavel
#include <iostream>

using namespace std;

int main(){

    float n = 1.5;
    float *p = &n;

    //Acessando o valor tanto pela variavel quanto pelo pointer
    //Acesso direto e indireto
    cout << n << " " << *p << endl;

    *p = 9.1;
    cout << n << " " << *p << endl;

    return 0;
}