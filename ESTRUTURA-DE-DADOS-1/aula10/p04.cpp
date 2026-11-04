// Busca no vetor

#include <iostream>
#include <vector>
#include <algorithm>

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
    v.push_back("F");
    v.push_back("H");

    auto it = find(v.begin(),v.end(),"F");; // find do container 'algorithm'
    // find retorna a primeira ocorrência

    /*
    Se find retornar o mesmo endereco do v.end(),
    significa que percorreu todo vector e não encontrou
    o elemento procurado;
    */
    if(it == v.end()){          // Não existe o elemento procurado;
        cout << "Not found\n";
    }else{                      // Existe o elemento procurado;
        v.insert(it, "Z"); 
        // Insere  a string 'Z' na posição it;
    }
    for(auto n:v){
        cout << n << endl;
    }

    v.clear(); // Deleta todo conteúdo do vector;

    cout << "Tamanho: " << v.size()
         << " Capacidade: " << v.capacity()
         << endl;


    return 0;
}