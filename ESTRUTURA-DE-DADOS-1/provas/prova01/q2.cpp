#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct participante {
    string nome;
    float nf;
    int nt;
    int np;
    int proj;
};

bool ordena(const participante &a, const participante &b){
    return a.nf > b.nf ||
           a.nf == b.nf && a.np > b.np ||
           a.nf == b.nf && a.np == b.np && a.proj > b.proj ||
           a.nf == b.nf && a.np == b.np && a.proj == b.proj && a.nome < b.nome;
}

int main(){
    int N;
    cin >> N;
    participante p[N];

    // Preencher vetor
    for(int i=0;i<N;i++){
        cin >> p[i].nome
            >> p[i].nt
            >> p[i].np
            >> p[i].proj;
    }

    /* Teste
    cout << endl;
    for(int i=0;i<N;i++){
    cout << p[i].nome << " "
         << p[i].nt << " "
         << p[i].np << " "
         << p[i].proj
         << endl;
    }*/


    // Calcular média
    float media;
    float soma;
    for(int i=0;i<N;i++){
        soma = p[i].nt + p[i].np;
        media = soma/2;
        p[i].nf = media;
    }
    
    // Ordenar
    sort(p,p+N,ordena);

    // Exibir
    cout << fixed << setprecision(2) << endl;

    for(int i=0;i<N;i++){
        cout << p[i].nome << " "
             << p[i].nf
             << endl;
    }

    return 0;
};


