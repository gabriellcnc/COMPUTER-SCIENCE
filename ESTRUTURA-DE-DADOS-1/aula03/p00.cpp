#include <iostream>

using namespace std;

void imprimr(string texto){
    cout << "O texto recebido foi: " << texto << endl;
}

int adiciona(int x, int y){
    int t = x + y;

    return t;
}

int main(){
    imprimr("Olá Função");
    int x = 10;
    int y = 2;
    int t = 500;
    int valor = adiciona(x,y);
    cout << "Soma: " << valor << endl;
    cout << "Valor da variavel 't' na main: " << t << endl;

    
    return 0;
}