#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    char choice = 'y';  // Brugerens valg for at starte et nyt regnestykke eller ej

    while (true) {
        if (choice == 'n') {
            break;  // Afslut programmet, hvis brugeren trykker 'n' for at stoppe
        }

        // Start nyt regnestykke
        string input;
        cout << "Indtast et regnestykke (f.eks. 1 + 5 - 2): ";
        getline(cin, input);

        stringstream ss(input);
        char op = '+';  // Initial operator for første tal
        int result = 0, num;

        // Læs første tal og start beregningen
        ss >> num;
        result += num;

        // Loop for fortsatte beregninger på samme regnestykke
        while (true) {
            ss >> op;  // Læs næste operator
            if (ss.fail()) break;  // Hvis der ikke er flere operatorer, bryd ud af løkken

            ss >> num;  // Læs næste tal
            if (op == '+') {
                result += num;
            } else if (op == '-') {
                result -= num;
            } else if (op == '*') {
                result *= num;
            } else if (op == '/') {
                if (num != 0) {
                    result /= num;
                } else {
                    cout << "Fejl: Division med 0!" << endl;
                    break;
                }
            }

            cout << "Midlertidigt resultat: " << result << endl;

            // Spørg om brugeren vil fortsætte eller starte et nyt regnestykke
            cout << "Vil du fortsætte med regnestykket? (y for fortsæt, n for nyt regnestykke): ";
            cin >> choice;
            cin.ignore();  // Ignorer newline-karakteren efter input

            if (choice == 'n') {
                break;  // Hvis brugeren vælger 'n', bryd ud af løkken for at starte forfra
            }
        }

        // Vis endelige resultat
        cout << "Slutresultat: " << result << endl;
        cout << "Vil du lave et nyt regnestykke? (n for at afslutte, y for at starte et nyt): ";
        cin >> choice;
        cin.ignore();  // Ignorer newline for korrekt getline
    }

    cout << "Programmet afsluttes." << endl;

    return 0;
}
