#include "../include/tokenizer.hpp"
#include <cctype>

std::vector<std::string> Tokenizer::tokenize(const std::string& expression) {
    std::vector<std::string> tokens;
    std::string num;
    
    for (char c : expression) {
        if (isdigit(c) || c == '.') {
            num += c; // Build number token
        } else {
            if (!num.empty()) {
                tokens.push_back(num); // Push number token
                num.clear();
            }
            if (!isspace(c)) {
                tokens.push_back(std::string(1, c)); // Push operator or parenthesis
            }
        }
    }
    if (!num.empty()) {
        tokens.push_back(num); // Push last number if any
    }
    return tokens;
}
