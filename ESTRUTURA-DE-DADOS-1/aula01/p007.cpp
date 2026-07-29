// Exemplo de laço de repetição

#include <iostream>

using namespace std;

int main(){
    int n = 0;
    cout << "Laço 'while' \n";
    /*
    Realiza o teste antes de entrar no loop
    -- Pode acontecer de nunca executar
    */

    while (n < 10){
        cout << n << endl;
        n++; // n += 1; - Incremento
    }   

    n = 0;
    cout << "Laçõ 'do while' \n";
    /*
    Executa ao menos 1 vez antes de testar
    */

    do{
        cout << n << endl;
        n++;
    }while(n < 10);

    n = 0:
    cout << "Laço 'for' \n"

    return 0;
}