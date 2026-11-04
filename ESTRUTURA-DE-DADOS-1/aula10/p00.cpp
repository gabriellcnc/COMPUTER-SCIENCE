// primeiro exemplo de std::vector - ArrayList

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v; // Vector de int inicialmente vazio
    cout << "Size: " << v.size() << endl;
    v.push_back(10); // Inserção no final
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.push_back(80);
    v.push_back(90);
    v.push_back(100);

    // Acessar valores
    for(int i=0; i<v.size(); i++){
        cout << i << ": " << v[i] << endl;
    }
    
    cout << endl;

    v.pop_back(); // Remove o ultimo elemento
    cout << v.size() << endl;

    for(int i=0; i<v.size(); i++){
        cout << i << ": " << v[i] << endl;
    }

    return 0;
};