//
// Created by lucas on 11/16/2025.
//

#include "EmployeeService.h"
#include "../suport/Support.h"
#include <fstream>
#include <iostream>
#include <stack>

EmployeeService::EmployeeService(Employee e) : e(e) {}

void EmployeeService::check() const {
    if (isCheckOut()) checkIn(); else checkOut();
}

bool EmployeeService::isCheckOut() const {

    std::ifstream file(e.getRegistro(), std::ios::in);

    if (!file.is_open()) {
        return true;
    }

    std::string line;
    std::string a;
    while (std::getline(file, line)) {
        a = line;
    }
    file.close();

    return a.front() == '2';
}

void EmployeeService::checkIn() const {
    Support support;

    std::ofstream file(e.getRegistro(), std::ios::app);

    if (!file.is_open()) {
        std::cout << "Erro: Nao foi possivel abrir o arquivo de registro." << std::endl;
        return;
    }

    file << "1," << support.getDate() << "\n";
    file.close();
    std::cout << "CheckIn registrado com sucesso!" << std::endl;
}

void EmployeeService::checkOut() const {
    Support support;

    std::ofstream file(e.getRegistro(), std::ios::app);

    if (!file.is_open()) {
        std::cout << "Erro: Nao foi possivel abrir o arquivo de registro." << std::endl;
        return;
    }

    file << "2," << support.getDate() << "\n";
    file.close();
    std::cout << "CheckOut registrado com sucesso!" << std::endl;
}

std::stack<std::string> EmployeeService::listAllRegister() {
    std::stack<std::string> registers;
    std::ifstream file(e.getRegistro(), std::ios::in);

    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return registers;
    }

    std::string line;
    while (std::getline(file, line)) {
        registers.push(line);
    }

    return registers;
}
