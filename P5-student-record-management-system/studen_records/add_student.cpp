#include <sqlite3.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>  // Tilføjet for at bruge time()
#include "student.hpp"
#include "student_generator.hpp"  // Indeholder generateRandomStudent

// Callback-funktion til at udskrive resultater
static int callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

// Funktion til at indsætte en studerende i databasen
void insertStudent(sqlite3* db, const Student& student) {
    char* errMsg = 0;
    std::string insertSQL = "INSERT INTO students (navn, alder, semester, studieretning, kontaktinfo) VALUES ('" +
                            student.getName() + "', " + std::to_string(student.getAge()) + ", " +
                            std::to_string(student.getSemester()) + ", '" + student.getStudieretning() + "', '" +
                            student.getKontaktinfo() + "');";

    int exit = sqlite3_exec(db, insertSQL.c_str(), NULL, 0, &errMsg);

    if (exit != SQLITE_OK) {
        std::cerr << "Error inserting data: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Student " << student.getName() << " inserted successfully!" << std::endl;
    }
}

// Funktion til at få brugerens input og oprette en studerende
Student createStudentFromInput() {
    std::string navn, studieretning;
    int alder, semester;

    std::cout << "Indtast navn: ";
    std::getline(std::cin, navn);

    std::cout << "Indtast alder: ";
    std::cin >> alder;
    std::cin.ignore();  // Ignorer newline efter alder-input

    std::cout << "Indtast semester: ";
    std::cin >> semester;
    std::cin.ignore();  // Ignorer newline efter semester-input

    std::cout << "Indtast studieretning: ";
    std::getline(std::cin, studieretning);

    return Student(semester, alder, navn, studieretning);
}

int main() {
    sqlite3* db;
    char* errMsg = 0;
    int exit;

    // Seed random generator én gang
    srand(static_cast<unsigned>(time(0)));

    // Åbn eller opret databasen
    exit = sqlite3_open("student_records.db", &db);

    if (exit) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return exit;
    } else {
        std::cout << "Database opened successfully!" << std::endl;
    }

    // Opret tabel
    const char* createTableSQL = "CREATE TABLE IF NOT EXISTS students ("
                                 "studentID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                 "navn TEXT NOT NULL, "
                                 "alder INTEGER NOT NULL, "
                                 "semester INTEGER NOT NULL, "
                                 "studieretning TEXT NOT NULL, "
                                 "kontaktinfo TEXT NOT NULL);";

    exit = sqlite3_exec(db, createTableSQL, NULL, 0, &errMsg);

    if (exit != SQLITE_OK) {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Table created successfully!" << std::endl;
    }

    // Loop til at oprette studerende, indtil brugeren vælger at stoppe
    char choice;
    do {
        std::cout << "\n--- Opret ny studerende ---\n";
        Student newStudent = createStudentFromInput();
        insertStudent(db, newStudent);

        std::cout << "Vil du oprette en ny studerende? (y/n): ";
        std::cin >> choice;
        std::cin.ignore();  // Ignorer newline efter input
    } while (choice == 'y' || choice == 'Y');

    // Hent og udskriv data fra databasen
    const char* selectSQL = "SELECT * FROM students;";
    exit = sqlite3_exec(db, selectSQL, callback, NULL, &errMsg);

    if (exit != SQLITE_OK) {
        std::cerr << "Error selecting data: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // Luk databasen
    sqlite3_close(db);
    return 0;
}
