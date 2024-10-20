#pragma once

#include <string>
#include <map>

class Student {
private:
    // Bruges i constructor
    int semester_; // Sættes til 1 ved default
    int alder_; // Sættes til 21 ved default
    std::string navn_; // Sættes til John Doe ved default
    std::string studieretning_; // Har ikke default
    // Oprettes i constructor
    std::string studentId_; // Oprettes som en kombi af året for start og et random 4-tal int
    std::string kontaktinfo_; // studentId@au.dk

public:
    // Constructor
    Student(int semester, int alder, std::string navn, std::string studieretning);

    // Destructor
    ~Student();

    // Getter-metoder for at kunne tilgå private variabler
    int getSemester() const { return semester_; }
    int getAge() const { return alder_; }
    std::string getName() const { return navn_; }
    std::string getStudieretning() const { return studieretning_; }
    std::string getStudentId() const { return studentId_; }
    std::string getKontaktinfo() const { return kontaktinfo_; }
};
