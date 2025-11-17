//
// Created by lucas on 11/16/2025.
//

#ifndef PONTO_SUPORT_H
#define PONTO_SUPORT_H

#include <string>

class Support {
    public:
        std::string getDate();
        std::string getLogsPath();
        std::string getDateFormat(std::string date);
};


#endif //PONTO_SUPORT_H