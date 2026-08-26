#include <utility>


template <typename T>
void bubblesort(T vet[], int n) {
  bool trocou;

  do {
    trocou = false;
    for (int i = 0; i < n - 1; i++) {
      if (vet[i] > vet[i + 1]) {
        std::swap(vet[i], vet[i + 1]);
        trocou = true;
      }
    }
  } while (trocou); // trocou == true
}

template <typename T>
void selectionsort(T vet[], int n) {
  for (int i = 0; i < n - 1; i++) {
    T menor = vet[i];
    int pos = i;

    for (int j = i+1; j < n; j++) {
      if (vet[j] < menor) {
        menor = vet[j];
        pos = j;
      }
    }
    std::swap(vet[i], vet[pos]);  // trocar vet[n-1] com vet[pos] 
  }
}

template <typename T>
void insertionsort(T vet[], int n) {
  for (int i = 1; i < n; i++) {
    T aux = vet[i]; // chave
    int j = i - 1;
    while (j >= 0 && vet[j] > aux) {
      vet[j + 1] = vet[j];
      j--;
    }
    vet[j + 1] = aux;
  }
}