// Percorere vector 'old school' e 'iterator'

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> v;
    
    v.push_back("A");
    v.push_back("B");
    v.push_back("C");
    v.push_back("D");
    v.push_back("E");
    v.push_back("F");
    v.push_back("G");
    v.push_back("H");
    
    cout << "Percorrer o vector no formato convêncional 'old school'\n";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
        // A B C D E F G H
    }

    cout << "Percorrer o vector no formato convêncional 'old school' de forma inversa\n";
    for(int i=v.size()-1; i>=0; i--){
        cout << v[i] << endl;
       }

    cout << "Iterando usando o 'range for'\n";
    for(auto n:v){
        cout << n << endl;
    }
    cout << "Percorre utilizando o iterator\n";
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << endl;
    }
    cout << "Percorre utilizando o reverse iterator\n";
    for(auto it = v.rbegin(); it != v.rend(); it++){
        cout << *it << endl;
    }



    return 0;
}