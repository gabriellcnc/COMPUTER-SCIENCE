// Biblioteca que implementa uma lista duplamente encadeada
// Nossa lib armazenará STRINGS
#include <iostream>
#include <string>

namespace UPF{

    struct node{
        std::string value;          // Valor
        node *previous = nullptr;   // Node anterior
        node *next = nullptr;       // Node posterior
    };

    struct list{
        // Variáveis de Controle 
        int num_nodes = 0; // QTD de elementos
        node *first = nullptr; // Primeiro node
        node *last = nullptr;  // Último node

        // Funções da biblioteca
        int size(){
            return num_nodes;
        }

        void push_front(const std::string &s){
            num_nodes++;
            node *p = new node; // Alocação de um espaçõ de mem. P/ o node.
            p->value = s;
            p->previous = nullptr;
            p->next = first;
            if(first != nullptr){ // Já existem elementos inseridos
                first->previous = p;
            }
            first = p;
            if(last == nullptr){ // Lista vazia
                last = p;
            }
        }

        void push_back(const std::string &s){
            num_nodes++;
            node *p = new node;
            p->value = s;
            p->next = nullptr;
            p->previous = last;
            if(last != nullptr){
                last->next = p;
            }
            last = p;
            if(first == nullptr){
                first = p;
            }
        }

        void print(){
            node *p = first; // Pega o end. do primeiro node
            while(p != nullptr){
                std::cout << '"'
                          << p->value
                          << '"'
                          << " ";
                p = p->next;
            }

        }

        int count(const std::string &s){
            node *p = first;
            int qtd = 0;
            while(p != nullptr){
                if(s == p->value){
                    qtd++;
                }
                p = p->next;
            }
            return qtd;
        }

        UPF::node* find(const std::string &s){
            node *p = first;
            while(p != nullptr){
                if(s == p->value){
                    return p;
                }
                p = p->next;
            }
            return p;
        }

    }; // Struct list

}   // Namespace UPF
