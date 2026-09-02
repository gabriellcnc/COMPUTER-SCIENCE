#include <iostream>
#include <algorithm>

bool ordena(float a, float b){
    return a > b;
}

using namespace std;

int main(){
    const int N=5;
    float vet[N]={9.5, 1.7, 1.6, 3.0, 6.3};
    sort(vet,vet+N,ordena);

    for(int i = 0; i<N; i++){
        cout << vet[i] << " ";
    }

    return 0;
}