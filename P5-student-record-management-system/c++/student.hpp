#pragma once

#include <string>

class Student{
private:
    std::string studentId_;
    int semester_;
    int alder_;
    std::string navn_;
    std::string studieretning_;
    std::string kontaktinfo_;

public:
    Student(int, int, int, std::string, std::string, std::string);

    ~Student();

    bool isValidName(const std::string&); // Validering af "navn" for studerende 
};