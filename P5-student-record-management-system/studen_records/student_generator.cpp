#include <random>    // For C++11 random number generation
#include <vector>
#include <string>
#include <cstdlib>    // Til rand() og srand()
#include <ctime>      // Til tidsbaseret seed for rand()
#include <iostream>

#include "student.hpp"
#include "student_generator.hpp"

// Lister med for- og efternavne
std::vector<std::string> first_name = {
    "Jakob", "Olivia", "Daniel", "Sara", "Clara", "Alexander", "Luna", "Viktor", "Julie", "Lærke",
    "Aksel", "Mathias", "Freja", "Jonathan", "Laura", "Oscar", "Andreas", "Frida", "Simon", "Nanna",
    "Ida", "Emma", "Carl", "Sofia", "Mikkel", "Alberte", "Maja", "William", "Patrick", "Ella",
    "Philip", "Karla", "Emil", "Mille", "Isabella", "Malthe", "Cecilie", "Adam", "Anna", "Benjamin",
    "Magnus", "Victoria", "Sebastian", "Josefine", "Christian", "Amalie", "Oliver", "Emilie", "Tobias",
    "Sofie", "Jonathan", "Agnes", "Frederik", "Patrick", "William"
};

std::vector<std::string> last_name = {
    "Nielsen", "Jensen", "Hansen", "Pedersen", "Andersen", "Christensen", "Larsen", "Sørensen", "Rasmussen", 
    "Jørgensen", "Madsen", "Kristensen", "Poulsen", "Johansen", "Knudsen", "Mortensen", "Olesen", "Eriksen", 
    "Mogensen", "Mikkelsen", "Holm", "Frederiksen", "Laursen", "Henriksen", "Simonsen", "Clausen", "Mathiesen", 
    "Bæk", "Bak", "Toft"
};

// Funktion til at generere et tilfældigt navn uden <random>
std::string generateRandomName(const std::vector<std::string>& fornavn, const std::vector<std::string>& efternavn) {
    // Brug rand() til at vælge tilfældige indekser
    int randomFornavnIndex = rand() % fornavn.size();
    int randomEfternavnIndex = rand() % efternavn.size();

    // Kombiner fornavn og efternavn
    std::string studentName = fornavn[randomFornavnIndex] + " " + efternavn[randomEfternavnIndex];

    return studentName;
}

std::string randomStudieretning() {
    std::vector<std::string> studieretninger = {"Software Engineering", "Medicin", "Law", "Communication", "Biology"};
    
    // Brug C++11 random number generator til at vælge et tilfældigt indeks
    std::random_device rd;  // Seed
    std::mt19937 gen(rd()); // Mersenne Twister generator
    std::uniform_int_distribution<> distrib(0, studieretninger.size() - 1);
    
    return studieretninger[distrib(gen)];
}

Student generateRandomStudent() {
    // Brug C++11 random number generator til at generere tilfældige værdier
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> semesterDistrib(1, 10);  // Semester mellem 1 og 10
    std::uniform_int_distribution<> ageDistrib(18, 28);      // Alder mellem 18 og 28

    int randomSemester = semesterDistrib(gen);
    int randomAlder = ageDistrib(gen);
    
    // Brug en funktion til at generere et tilfældigt navn
    std::string randomNavn = generateRandomName(first_name, last_name); 
    std::string randomStudieretningVal = randomStudieretning();

    return Student(randomSemester, randomAlder, randomNavn, randomStudieretningVal);
}
