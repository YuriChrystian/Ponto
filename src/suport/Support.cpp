//
// Created by lucas on 11/16/2025.
//

#include "Support.h"

#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <iostream>

std::string Support::getDate() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t timeValue = std::chrono::system_clock::to_time_t(now);

    std::tm* localTime = std::localtime(&timeValue);

    std::ostringstream os;
    os << std::put_time(localTime, "%d%m%Y%H%M%S");

    return os.str();
}

std::string Support::getDateFormat(std::string data) {
    size_t pos = data.find(',');

    std::string date = data.substr(pos + 1);
    std::string dateFormat;

    for (int index = 0; index < date.length(); index++) {

        dateFormat.push_back(date[index]);

        if (index == 1 || index == 3) {
            dateFormat.push_back('/');
        } else if (index == 7) {
            dateFormat.push_back(' ');
        } else if (index == 9 || index == 11 ) {
            dateFormat.push_back(':');
        }
    }
    return dateFormat;
}

std::string Support::getLogsPath() {
    std::filesystem::path currentDir = std::filesystem::current_path();
    std::filesystem::path logsPath;

    if (currentDir.filename() == "cmake-build-debug") {
        logsPath = currentDir.parent_path() / "logs";
    } else {
        logsPath = currentDir / "logs";
    }
    
    return logsPath.string();
}
