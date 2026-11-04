// Vai pedir na prova

/*
Tamanho e capacidade sâo coisas diferentes;

Size = a qtd de elementos;
Capacity = A capacidade moemntanea de elementos.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<double> v;
    cout << "Digite 0 p/ SAIR\n";
    double x;

    cout << "Tamanho: " << v.size()
         << " Capacidade: " << v.capacity()
         << endl;
         
    // com >> x -> Lê até o EOF - END OF FILE
    // e segue a leitura enquanto for diferente de zero
    while(cin >> x && x!=0){
        v.push_back(x);
        cout << "Tamanho: " << v.size()
         << " Capacidade: " << v.capacity()
         << endl;
    }


    return 0;
}