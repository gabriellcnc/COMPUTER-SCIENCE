//exemplo de if e else

#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Informe um valor inteiro: ";
    cin >> n;

    // && = AND
    // || = OR
    
    // Se n é maior que 10 e menor que 20
    if(n > 10 && n < 20){
        cout << "ok!\n"; // '\n' e 'endl' ambos quebram linha
    }else{
        cout << "Não!\n";
    }

    return 0;
}