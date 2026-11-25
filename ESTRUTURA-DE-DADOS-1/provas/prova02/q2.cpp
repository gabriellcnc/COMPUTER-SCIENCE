#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

int main(){

    int n;
    float soma = 0;
    float media = 0;
    list<int> Iniciantes;
    list<int> Veteranos;
    list<int> l;

    while(cin >> n){
        if(n<0){
            break;
        }
        if(n<1000){
            Iniciantes.push_front(n);
            l.push_front(n);
        }
        if(n>=1000){
            Veteranos.push_front(n);
            l.push_front(n);
        }
    }

    Iniciantes.sort([](const int &a, const int &b){return a < b;});
    Veteranos.sort([](const int &a, const int &b){return a > b;});
    
    for(auto n:l){
        soma = soma + n;
    }
    media = soma / l.size();

    cout << fixed << setprecision(2);

    cout << "--- RESULTADOS ---" << endl
         << "Jogadores Iniciantes: " << Iniciantes.size() << endl
         << "Jogadores Veteranos: " << Veteranos.size() << endl;
    
    cout << "XP Iniciantes (crescente): ";
    for(auto n:Iniciantes){cout << n << " ";}

    cout << endl << "XP Veterandos (decresente): ";
    for(auto n:Veteranos){cout << n << " ";}

    cout << endl << "Média global de XP: " << media << endl;
    
    cout << "Maior XP Iniciante: ";
    auto mai = Iniciantes.rbegin();
    cout << *mai << endl;

    cout << "Menor XP Iniciante: ";
    auto mii = Iniciantes.begin();
    cout << *mii << endl;

    cout << "Maior XP Veterano: ";
    auto mav = Veteranos.begin();
    cout << *mav << endl;

    cout << "Menor XP Veterano: ";
    auto miv = Veteranos.rbegin();
    cout << *miv << endl;

    return 0;
};