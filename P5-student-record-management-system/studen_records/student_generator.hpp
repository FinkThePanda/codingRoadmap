#pragma once

#include <vector>
#include <string>
#include "student.hpp"

// Deklaration af funktionerne
std::string randomStudieretning();
Student generateRandomStudent();

// Deklaration af funktionen til at generere et tilfældigt navn
std::string generateRandomName(const std::vector<std::string>& fornavn, const std::vector<std::string>& efternavn);
