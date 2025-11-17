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

std::stack<std::string> RegisterService::getAll() {
    std::ifstream file(e.getRegistro(), std::ios::in);
    std::stack<std::string> lines;

    if (!file.is_open()) {
        return {};
    }

    std::string line;

    int qLinha = 0;

    while (std::getline(file, line)) {
        qLinha++;
        if (line.front() == '1') {
            lines.push("Check-In em " + support.getDateFormat(line));
        } else {
            lines.push("Check-Out em " + support.getDateFormat(line));
        }
    }

    if (qLinha == 0) {
        return {};
    }

    return lines;
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
