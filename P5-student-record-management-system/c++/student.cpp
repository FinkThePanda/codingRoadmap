#include <iostream>
#include <string>
#include <ctime>
#include <random>


#include "student.hpp"



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
    // et student id består af årstallet for start på studie, samt 4 ekstra tal (8 tal i det hele).
     
    // Få det nuværende tidspunkt
    std::time_t t = std::time(nullptr); 
    
    // Konverter til lokal tid
    std::tm* localTime = std::localtime(&t);
    
    // Opret en tilfældig number generator
    std::random_device rd;  // Bruges til at få et seed
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine
    std::uniform_int_distribution<> distrib(0000, 9999); // Fordeling for 4-cifrede tal

    // Få det aktuelle år (skal lægges 1900 til, da `tm_year` giver år siden 1900)
    studentId_ = std::to_string(1900 + localTime->tm_year) + std::to_string(distrib(gen));


    // Dette system kan kun support 1-6 semestre. Hvis der ikke gives en value, sætte semester til 1
    if (semester >= 1 || semester <= 6){
        semester_ = semester;
    }
    else {
        semester_ = 1;
    }

    // Alder kan være fra 18-60. Hvis en alder ikke vælges, bruges en gennemsnitalder for universitetstuderende (21 år)
    if (alder > 18 && alder < 60){
        alder_ = alder;
    }
    else{
        alder_ = 21;
    }

    // Et navn skal bestå af mindst 1 fornavn og et efternavn

    if (isValidName(navn)){
        navn_ = navn;
    }
    else {
        navn_ = "John Doe";
    }

    // Der kan vælges mellem 5 gyldige studieretninger
    /*
     * Software Enginieering
     * Medicin
     * Law
     * Communication
     * Biology
    */
   if (
    studieretning == "Software Enginieering" || 
    studieretning == "Medicin" ||
    studieretning == "Law" ||
    studieretning == "Communication" ||
    studieretning == "Biology")
    {
        studieretning_ = studieretning;
    }
    else {
        std::cout << "ERROR: ikke en valid studieretning" << std::endl;
    }

    // Kontaktinfo vil blive oprettet ud fra studentID. Den vil følge denne formel
    // studentId@au.dk
    kontaktinfo_ = std::to_string(studentId_) + "@au.dk";
}

// ######## karakterblad #############
 void Student::tilføjKarakter(std::string fag, int karakter)
 {
    karakterblad[fag] = karakter; 
 }


void Student::udskrivKarakterblad() const
{
    for (const auto& pair : karakterblad) {
        std::cout << "Fag: " << pair.first << " - Karakter: " << pair.second << std::endl;
    }
  }


void Student::printGennemsnit(const std::map<std::string, int>& karakterblad)
{
    if (karakterblad.empty()) {
        std::cout << "Ingen karakterer tilgængelige." << std::endl;
        return;
    }

    int sum = 0;
    for (const auto& pair : karakterblad) {
        sum += pair.second; // Summér alle karaktererne
    }

    double gennemsnit = static_cast<double>(sum) / karakterblad.size(); // Beregn gennemsnittet
    std::cout << "Gennemsnit af karakterer: " << gennemsnit << std::endl;
}