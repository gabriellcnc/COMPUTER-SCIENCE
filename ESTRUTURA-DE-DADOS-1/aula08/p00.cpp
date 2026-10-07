/*
Primeiro exemplo utilizando fila
FIFO = First In First Out
Primeiro a entrar é o primeiro a sair
*/

#include <iostream>
#include <queue> // Biblioteca (container) std::queue - Implementa uma fila

using namespace std;

int main(){

    queue<int> fila;
    fila.push(100);
    fila.push(200);
    fila.push(300);
    fila.push(400);
    fila.push(500);
    fila.push(600);

    // Executa quando tem elementos na fila
    while(!fila.empty()){ // while(fila.size()>0)

        cout << "Tamanho da fila: " << fila.size() << endl; // Tamanho
        cout << "Front: " << fila.front() << endl; // Priemiro elemento
        cout << "Back: " << fila.back() << endl; // Ultimo elemento
        cout << endl;
        fila.pop(); // Remove o primeiro elemento da fila
    }

    return 0;
};