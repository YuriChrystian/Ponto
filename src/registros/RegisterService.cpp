//
// Created by lucas on 11/16/2025.
//

#include "RegisterService.h"

#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include "../Employee.h"
#include "../suport/Support.h"

RegisterService::RegisterService(Employee e) : e(e) {}

Lista* RegisterService::getAll() {
    std::ifstream file(e.getRegistro(), std::ios::in);
    std::stack<std::string> lines;
    auto* l = new Lista();

    if (!file.is_open()) {
        return nullptr;
    }

    std::string line;

    int qLinha = 0;

    while (std::getline(file, line)) {
        qLinha++;
        EmployeeItem litem;
        litem.date =  support.getDateFormat(line);
        if (line.front() == '1') {
            litem.type = 1;
        } else {
            litem.type = 2;
        }
        l->inserirInicio(litem);
    }

    if (qLinha == 0) {
        return nullptr;
    }

    return l;
}

Dashboard* RegisterService::getDashboard() {
    Dashboard* dashboard = new Dashboard();
    Support support;

    dashboard->qCheckIn = 0;
    dashboard->qCheckOut = 0;

    std::ifstream file(e.getRegistro(), std::ios::in);

    if (!file.is_open()) {
        return nullptr;
    }

    std::string line;
    std::string lastLine;
    int qLinha = 0;

    while (std::getline(file, line)) {
        lastLine = line;
        qLinha++;
        if (line.front() == '1') {
            dashboard->qCheckIn = dashboard->qCheckIn + 1;
            dashboard->typeLast = 1;
        } else {
            dashboard->qCheckOut = dashboard->qCheckOut + 1;
            dashboard->typeLast = 2;
        }
    }

    if (qLinha == 0) {
        return nullptr;
    }

    dashboard->lastDate = support.getDateFormat(lastLine);;

    return dashboard;
}
