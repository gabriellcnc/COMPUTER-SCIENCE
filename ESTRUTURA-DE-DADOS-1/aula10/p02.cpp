#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cout << "De o tamanho minimo do vector\n";
    cin >> n;
    vector<string> v(n); // tamanho (mínimo)

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    cout << "Tamanho: " << v.size()
         << " Capacidade: " << v.capacity()
         << endl;

    v.push_back("S1mple");
    v.push_back("TAC0");

    cout << "Tamanho: " << v.size()
         << " Capacidade: " << v.capacity()
         << endl;
    return 0;
}