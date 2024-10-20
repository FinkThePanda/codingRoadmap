#include "../include/calculator.hpp"
#include <stack>
#include <stdexcept>
#include <cctype>

// Helper functions
int Calculator::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool Calculator::isLeftAssociative(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

// Converts infix expression to postfix notation
std::vector<std::string> Calculator::infixToPostfix(const std::vector<std::string>& tokens) {
    std::stack<std::string> operators;
    std::vector<std::string> output;

    for (const std::string& token : tokens) {
        if (isdigit(token[0])) {
            output.push_back(token); // Operand
        } else if (token == "(") {
            operators.push(token);
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != "(") {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else {
            // Operator
            while (!operators.empty() && precedence(operators.top()[0]) >= precedence(token[0])) {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }
    
    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}

// Evaluates a postfix expression
double Calculator::evaluatePostfix(const std::vector<std::string>& tokens) {
    std::stack<double> values;

    for (const std::string& token : tokens) {
        if (isdigit(token[0])) {
            values.push(std::stod(token)); // Push number
        } else {
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            
            if (token == "+") values.push(a + b);
            else if (token == "-") values.push(a - b);
            else if (token == "*") values.push(a * b);
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Division by zero");
                values.push(a / b);
            }
        }
    }

    return values.top();
}
