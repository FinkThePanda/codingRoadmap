#include <iostream>
#include "../include/tokenizer.hpp"
#include "../include/calculator.hpp"

int main() {
    std::string expression;
    std::cout << "Enter expression: ";
    std::getline(std::cin, expression);

    // Tokenize the input expression
    Tokenizer tokenizer;
    std::vector<std::string> tokens = tokenizer.tokenize(expression);

    // Convert infix to postfix and evaluate the result
    Calculator calculator;
    std::vector<std::string> postfix = calculator.infixToPostfix(tokens);
    double result = calculator.evaluatePostfix(postfix);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
