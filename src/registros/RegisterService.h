//
// Created by lucas on 11/16/2025.
//

#ifndef PONTO_REGISTERSERVICE_H
#define PONTO_REGISTERSERVICE_H
#include <stack>
#include <string>
#include "../Employee.h"
#include "../suport/Support.h"

struct Dashboard {
    int qCheckIn;
    int qCheckOut;

    int typeLast;
    std::string lastDate;
};

class RegisterService {
private:
    Employee e;
    Support support;
public:
    RegisterService(Employee e);
    Dashboard *getDashboard();
    std::stack<std::string> getAll();

};

#endif //PONTO_REGISTERSERVICE_H
