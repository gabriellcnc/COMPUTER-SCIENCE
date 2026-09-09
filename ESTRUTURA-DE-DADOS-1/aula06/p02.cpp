// Arrays com struct
#include <iostream>
using namespace std;

struct aluno{
    int matricula;
    string nome;
    float nota;
};

const int NA = 5; // Número de alunos

int main(){
    // Criar o vetor
    aluno turma[NA]= {
        {214143, "Gabriel Cenci", 10.00},  // 0  }
        {214144, "Mariana Silva", 9.50},   // 1  }
        {214145, "Lucas Oliveira", 8.75},  // 2  } ÍNDICES
        {214146, "Beatriz Santos", 10.00}, // 3  }
        {214147, "Matheus Pereira", 7.20}  // 4  }
    };
    
    // Exibir o vetor
    for(int i=0; i<NA; i++){
        cout << "Matrícula: " << turma[i].matricula << endl;
        cout << "Nome: " << turma[i].nome << endl;
        cout << "Nota: " << turma[i].nota << endl << endl;
        
    };
    
    return 0;
};