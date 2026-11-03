#include <iostream>

using namespace std;

int main(){

    int v[3]={10,20,30};
    // o nome do array é o end. do seu primeiro elemento
    cout << v << endl;

    int *p;
    p = v; // p =&v[0]; // Para arrays não precisa do '&'
    cout << p << "  " << *p << endl;
    p++;
    cout << p << "  " << *p << endl;
    p++;
    cout << p << "  " << *p << endl;


    return 0;
}