//
// Created by lucas on 11/16/2025.
//

#ifndef EmployeeService_h
#define EmployeeService_h

#include <stack>

#include "../Employee.h"

class EmployeeService {
    private:
        void checkIn() const;
        void checkOut() const;

    public:
        Employee e;
        EmployeeService(Employee e);
        std::stack<std::string> listAllRegister();
        void check() const;
        bool isCheckOut() const;
};


#endif //PONTO_FUNCIONARIOSERVICE_H