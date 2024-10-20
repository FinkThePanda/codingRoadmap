#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>
#include <string>

class Calculator {
public:
    // Converts an infix expression to postfix notation
    std::vector<std::string> infixToPostfix(const std::vector<std::string>& tokens);

    // Evaluates a postfix expression and returns the result
    double evaluatePostfix(const std::vector<std::string>& tokens);

private:
    // Helper functions
    int precedence(char op);
    bool isLeftAssociative(char op);
};

#endif // CALCULATOR_HPP
