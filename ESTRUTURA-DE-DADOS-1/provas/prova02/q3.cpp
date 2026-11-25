#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    int soma;
    queue<int> e;

    while(cin >> n){
        if(n == 0){
            cout << "Expediente encerrado. Caixas na esteira: "
                 << e.size() << endl;
            break;
        }
        if(e.empty() || (e.front() + n)>50){
            e.push(n);
            cout << "Caixa de " 
                 << n << " kg adicionada\n";
        }
        else{
            soma = e.front() + n;
            e.push(soma);
            cout << "Consolidada: "
                 << n << " + " << e.front() 
                 << " = " << soma << " kg\n";
            e.pop();
        }
    }

    return 0;
}