//
// Created by lucas on 11/16/2025.
//

#include "Employee.h"
#include "suport/Support.h"
#include <string>
#include <filesystem>

std::string Employee::getRegistro() const {
    Support support;
    std::filesystem::path logsPath = support.getLogsPath();
    return (logsPath / (std::to_string(funcional) + ".txt")).string();
}
