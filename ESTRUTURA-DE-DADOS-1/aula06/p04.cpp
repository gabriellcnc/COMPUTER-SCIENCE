// Ordenação de structs com multiplos criterios de ordenação
#include <iostream>
#include <algorithm>
using namespace std;

struct aluno{
    int matricula;
    string nome;
    float nota;
};

bool ordena(const aluno &a, const aluno &b){
    // Ordena o vetor por nota em ordem decrescente (>)
    /*
        > crescente
        < decresente
        1º criterio: nota em ordem decrescente
        2º critério: nome em ortem alfabetica
        3º critério: matrícula em ordem crescente
    */
    return (a.nota > b.nota) || //Primeiro critério
           (a.nota == b.nota && a.nome < b.nome) || // Segundo critério
           (a.nota == b.nota && a.nome < b.nome && a.matricula < b.matricula); // Terceiro critério
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

    // Ordenar o vetor
    sort(turma,turma+NA,ordena);
    
    // Exibir o vetor
    for(int i=0; i<NA; i++){
        cout << "Matrícula: " << turma[i].matricula << endl;
        cout << "Nome: " << turma[i].nome << endl;
        cout << "Nota: " << turma[i].nota << endl << endl;
        
    };
    
    return 0;
};