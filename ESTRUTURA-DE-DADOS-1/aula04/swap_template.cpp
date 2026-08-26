//Exemplo uso de template de funções

#include <iostream>
using namespace std;

// Template de função para trocar dois valores de qualquer tipo T
template <typename T>
void swapValores(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Antes do swap (int): x = " << x << ", y = " << y << endl;
    swapValores(x, y);
    cout << "Depois do swap (int): x = " << x << ", y = " << y << endl;

    double a = 1.5, b = 3.7;
    cout << "\nAntes do swap (double): a = " << a << ", b = " << b << endl;
    swapValores(a, b);
    cout << "Depois do swap (double): a = " << a << ", b = " << b << endl;

    string s1 = "Olá", s2 = "Mundo";
    cout << "\nAntes do swap (string): s1 = " << s1 << ", s2 = " << s2 << endl;
    swapValores(s1, s2);
    cout << "Depois do swap (string): s1 = " << s1 << ", s2 = " << s2 << endl;

    return 0;
}
