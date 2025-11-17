cmake_minimum_required(VERSION 4.0)
project(ponto)

set(CMAKE_CXX_STANDARD 17)

add_executable(ponto main.cpp
        src/Employee.cpp
        src/employee/EmployeeService.cpp
        src/employee/EmployeeService.h
        src/Employee.h
        src/suport/Support.cpp
        src/suport/Support.h
        src/registros/RegisterService.cpp
        src/registros/RegisterService.h)

# Link filesystem library if needed (for GCC)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(ponto stdc++fs)
endif()
