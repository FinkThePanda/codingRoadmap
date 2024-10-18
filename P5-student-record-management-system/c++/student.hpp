#pragma once

#include <string>
#include <map>

class Student{
private:
    std::string studentId_;
    int semester_;
    int alder_;
    std::string navn_;
    std::string studieretning_;
    std::string kontaktinfo_;

    // Opret vector for hver elev, som indeholder deres karakterer
    std::map<std::string, int> karakterblad;

public:
    Student(int, int, int, std::string, std::string, std::string);

    ~Student();

    bool isValidName(const std::string&); // Validering af "navn" for studerende 

    // function til og tilføje karakter til map (skal have 2 inputs, nemlig "Fag" og "Karakter")
    void tilføjKarakter(std::string, int);


    // function til og udskrive alle karakterer
    void udskrivKarakterblad() const;


    // Function til at beregne og returnerer en studerendes "gennemsnit" baseret på karakterer fundet i map
    void printGennemsnit(const std::map<std::string, int>&);

};