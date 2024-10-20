#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include "student.hpp"

// Function til at validere navn
bool isValidName(const std::string& name) 
{
    // Check if there is at least one space in the name
    size_t spacePos = name.find(' ');
    return (spacePos != std::string::npos) && (spacePos != 0) && (spacePos != name.length() - 1);
}

Student::Student(
    int semester, 
    int alder, 
    std::string navn, 
    std::string studieretning)
{
    // Et student ID består af årstallet for start på studie, samt 4 ekstra tal (8 tal i det hele).
     
    // Få det nuværende tidspunkt
    std::time_t t = std::time(nullptr); 
    
    // Konverter til lokal tid
    std::tm* localTime = std::localtime(&t);
    
    // Opret en tilfældig number generator
    std::random_device rd;  // Bruges til at få et seed
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine
    std::uniform_int_distribution<> distrib(0, 9999); // Fordeling for 4-cifrede tal

    // Få det aktuelle år (skal lægges 1900 til, da `tm_year` giver år siden 1900)
    studentId_ = std::to_string(1900 + localTime->tm_year) + std::to_string(distrib(gen));

    // Dette system kan kun supportere 1-6 semestre. Hvis der ikke gives en value, sættes semester til 1
    if (semester >= 1 && semester <= 6) {
        semester_ = semester;
    }
    else {
        semester_ = 1;
    }

    // Alder kan være fra 18-60. Hvis en alder ikke vælges, bruges en gennemsnitalder for universitetstuderende (21 år)
    if (alder >= 18 && alder <= 60) {
        alder_ = alder;
    }
    else {
        alder_ = 21;
    }

    // Et navn skal bestå af mindst 1 fornavn og et efternavn
    if (isValidName(navn)) {
        navn_ = navn;
    }
    else {
        navn_ = "John Doe";
    }

    // Der kan vælges mellem 5 gyldige studieretninger
    if (studieretning == "Software Engineering" || 
        studieretning == "Medicin" ||
        studieretning == "Law" ||
        studieretning == "Communication" ||
        studieretning == "Biology") 
    {
        studieretning_ = studieretning;
    }
    else {
        std::cout << "ERROR: Ikke en valid studieretning" << std::endl;
    }

    // Kontaktinfo vil blive oprettet ud fra studentID. Den vil følge denne formel
    // studentId@au.dk
    kontaktinfo_ = studentId_ + "@au.dk";
}

// Implementér destruktøren
Student::~Student() {
    // Tom destruktør, da der ikke er nogen dynamisk allokeret hukommelse
}