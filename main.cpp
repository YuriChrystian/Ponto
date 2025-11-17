#include <iomanip>
#include <iostream>
#include <vector>

#include "src/Employee.h"
#include "src/employee/EmployeeService.h"
#include "src/registros/RegisterService.h"

int menu() {
    int opcao = 0;

    std::cout << "=== Sistema de Ponto ===" << std::endl;
    std::cout << "1 - Bater ponto (Check-in;Check-out)" << std::endl;
    std::cout << "2 - Estatisticas" << std::endl;
    std::cout << "3 - Exibir espelho" << std::endl;
    std::cout << "0 - Sair" << std::endl;
    std::cout << "Escolha uma opcao: ";

    std::cin >> opcao;
    return opcao;
}

void resetCout() {
    std::cout << "\nPressione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

struct RegisterTemp {
    std::string tipo;
    std::string dataHora;
};

void printDashboardTable(Dashboard dashboard) {

    std::string action;

    if (dashboard.typeLast == 1) {
        action = "Check-In";
    } else {
        action = "Check-Out";
    }

    std::string date = dashboard.lastDate.substr(0, 10);   // 17/11/2025
    std::string hour = dashboard.lastDate.substr(11);      // 00:25:32

    std::cout << "+-------------------------+--------------------------+\n";
    std::cout << "|        Campo            |          Valor           |\n";
    std::cout << "+-------------------------+--------------------------+\n";

    std::cout << "| " << std::left << std::setw(23) << "Quantidade de CheckIn"
              << " | " << std::setw(25) << dashboard.qCheckIn << "|\n";

    std::cout << "| " << std::left << std::setw(23) << "Quantidade de CheckOut"
              << " | " << std::setw(25) << dashboard.qCheckOut << "|\n";

    std::cout << "| " << std::left << std::setw(23) << "Ultimo ponto"
              << " | " << std::setw(25) << (action + " em " + date) << "|\n";

    std::cout << "| " << std::left << std::setw(23) << "Ultimo horario"
              << " | " << std::setw(25) << hour << "|\n";

    std::cout << "+-----------------------+---------------------------+\n";
}

void printTable(std::stack<std::string> linhas) {

    std::vector<RegisterTemp> registros;

    while (!linhas.empty()) {
        std::string linha = linhas.top();
        linhas.pop();

        size_t pos = linha.find(" em ");
        if (pos != std::string::npos) {
            registros.push_back({
                linha.substr(0, pos),      // Check-In / Check-Out
                linha.substr(pos + 4)      // Data e hora
            });
        }
    }

    std::cout << "+-----------+-----------------------+" << std::endl;
    std::cout << "|   Acao    | Data e Hora           |" << std::endl;
    std::cout << "+-----------+-----------------------+" << std::endl;

    for (auto& r : registros) {
        std::cout << "| "
                  << std::left << std::setw(9) << r.tipo
                  << " | "
                  << std::left << std::setw(21) << r.dataHora
                  << " |" << std::endl;
    }

    std::cout << "+-----------+-----------------------+" << std::endl;
}

int main() {
    Employee employee;
    std::cout << "=== Ola, funcionario ===" << std::endl;
    std::cout << "Informe a sua funcional: ";

    std::cin >> employee.funcional;

    if (employee.funcional == 0) {
        std::cout << "Modo ADM: " << std::endl;
        return 0;
    }

    EmployeeService employeeService(employee);
    RegisterService registerService(employee);

    bool _runner = true;
    while (_runner) {
        system("cls");
        int opcao = menu();
        switch (opcao) {
            default:
                std::cout << "Opcao invalida! Tente novamente." << std::endl;
                resetCout();
                break;
            case 0:
                std::cout << "Saindo do sistema..." << std::endl;
                _runner = false;
                break;
            case 1:
                employeeService.check();
                resetCout();
                break;
            case 2: {
                const Dashboard *dash = registerService.getDashboard();

                if (dash == nullptr) {
                    std::cout << "Funcionario sem informacoes" << std::endl;
                    resetCout();
                    break;
                }

                printDashboardTable(*dash);
                resetCout();
                break;
                std::cout << "Quantidade de CheckIn " << dash->qCheckIn << std::endl;
                std::cout << "Quantidade de CheckOut " << dash->qCheckOut << std::endl;
                std::cout << "Ultimo ponto ";
                if (dash->typeLast == 1) {
                    std::cout << " Check-I";
                } else {
                    std::cout << " Check-Out ";
                }
                std::cout << " Em " << dash->lastDate << std::endl;
                resetCout();
                delete dash;
                break;
            }
            case 3:
                auto* list = registerService.getAll();
                list->exibirLista();
                resetCout();

                // if (lines.empty()) {
                //     std::cout << "Nenhum registro para esse funcionario" << std::endl;
                //     resetCout();
                // } else {
                //     printTable(lines);
                //     resetCout();
                // }
                break;
        }
    }

    return 0;
}
