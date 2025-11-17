//
// Created by lucas on 11/16/2025.
//

#ifndef PONTO_REGISTERSERVICE_H
#define PONTO_REGISTERSERVICE_H
#include <iostream>
#include <stack>
#include <string>
#include "../Employee.h"
#include "../suport/Support.h"

class Lista;

struct Dashboard {
    int qCheckIn;
    int qCheckOut;

    int typeLast;
    std::string lastDate;
};

struct EmployeeItem {
    int type;
    std::string date;
};

struct No {
    EmployeeItem dado;
    No* anterior;
    No* proximo;

    No(EmployeeItem dado) : dado(dado), anterior(nullptr), proximo(nullptr) {}
};

class RegisterService {
private:
    Employee e;
    Support support;

public:
    RegisterService(Employee e);

    Dashboard* getDashboard();

    Lista* getAll();
};

class Lista {
private:
    No* inicio;
    No* fim;

public:
    Lista() : inicio(nullptr), fim(nullptr) {}

    void inserirInicio(EmployeeItem valor) {
        No* novo = new No(valor);
        novo->proximo = inicio;

        if (inicio != nullptr)
            inicio->anterior = novo;
        else
            fim = novo;

        inicio = novo;
    }

    void inserirFim(EmployeeItem valor) {
        No* novo = new No(valor);
        novo->anterior = fim;

        if (fim != nullptr)
            fim->proximo = novo;
        else
            inicio = novo;

        fim = novo;
    }

    void exibirListaReversa() const {
        No* atual = fim;
        std::cout << "Lista (reversa): ";
        while (atual != nullptr) {
            if (atual->dado.type == 1) {
                std::cout << "Check In realizado em " << atual->dado.date << std::endl;
            } else {
                std::cout << "Check Out realizado em " << atual->dado.date << std::endl;
            }
            atual = atual->anterior;
        }
        std::cout << std::endl;
    }

    void exibirLista() const {
        No* atual = inicio;

        if (atual == nullptr) {
            std::cout << "Nenhum registro encontrado" << std::endl;
            return;
        }
        std::cout << std::endl;
        while (atual != nullptr) {
            if (atual->dado.type == 1) {
                std::cout << "Check In realizado em " << atual->dado.date << std::endl;
            } else {
                std::cout << "Check Out realizado em " << atual->dado.date << std::endl;
            }
            atual = atual->proximo;
        }
        std::cout << std::endl;
    }

    // void removerValor(int valor) {
    //     No* atual = inicio;
    //     while (atual != nullptr && atual->dado != valor)
    //         atual = atual->proximo;
    //
    //     if (atual == nullptr) {
    //         std::cout << "Valor " << valor << " não encontrado!" << std::endl;
    //         return;
    //     }
    //
    //     if (atual->anterior != nullptr)
    //         atual->anterior->proximo = atual->proximo;
    //     else
    //         inicio = atual->proximo;
    //
    //     if (atual->proximo != nullptr)
    //         atual->proximo->anterior = atual->anterior;
    //     else
    //         fim = atual->anterior;
    //
    //     delete atual;
    //     std::cout << "Valor " << valor << " removido!" << std::endl;
    // }

    ~Lista() {
        No* atual = inicio;
        while (atual != nullptr) {
            No* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
    }
};

#endif //PONTO_REGISTERSERVICE_H
