#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <vector>
#include <string>

class Tokenizer {
public:
    // Tokenizes a mathematical expression string
    std::vector<std::string> tokenize(const std::string& expression);
};

#endif // TOKENIZER_HPP
