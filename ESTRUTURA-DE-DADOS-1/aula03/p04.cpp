// Primeiro exemplo utilizando TDD
// TDD: Test Driven Development
// Desenvolvimento orientado a testes

// assert - Verifica se a condição satisfaz o resultado esperado
#include <iostream>
#include <cassert>
#include "funcoes.cpp"

using namespace std;

int main(){
    
    assert(fatorial(0) == 1);
    assert(fatorial(1) == 1);
    assert(fatorial(2) == 2);
    assert(fatorial(3) == 6);
    assert(fatorial(4) == 24);
    assert(fatorial(5) == 120);
    assert(fatorial(6) == 720);

    cout << "Passed!\n";

    return 0;
}