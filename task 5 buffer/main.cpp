#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


const size_t BUFFER_SIZE = 4096;


enum class TokenType {
    IDENTIFIER
};


struct Token {
    TokenType type;
    string value;

    Token(TokenType t, const string& v) : type(t), value(v) {}
};


class LexicalAnalyzer {
private:
    string buffer;       
    size_t position;     

     unordered_map<string, TokenType> keywords;  
     
    void initKeywords() {
        keywords["int"] = TokenType::KEYWORD;
        keywords["float"] = TokenType::KEYWORD;
        keywords["if"] = TokenType::KEYWORD;
        keywords["else"] = TokenType::KEYWORD;
        keywords["while"] = TokenType::KEYWORD;
        keywords["return"] = TokenType::KEYWORD;
    }


    
    bool isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    
    bool isAlphaNumeric(char c) {
        return isAlpha(c) || (c >= '0' && c <= '9');
    }

    
    string getNextIdentifier() {
        size_t start = position;
        while (position < buffer.length() && isAlphaNumeric(buffer[position])) {
            position++;
        }
        return buffer.substr(start, position - start);
    }

public:
    
    LexicalAnalyzer(const string& source) : buffer(source), position(0) {}

    
    vector<Token> tokenize() {
        vector<Token> tokens;

        while (position < buffer.length()) {
            char currentChar = buffer[position];

            
            if (!isAlpha(currentChar)) {
                position++;
                continue;
            }

            
            string identifier = getNextIdentifier();
            tokens.emplace_back(TokenType::IDENTIFIER, identifier);
        }

        return tokens;
    }
};


void printTokens(const vector<Token>& tokens) {
    for (const auto& token : tokens) {
        cout << "Type: IDENTIFIER, Value: " << token.value << endl;
    }
}


int main() {
    
    string filePath = "source_code.txt";

    
    ifstream file(filePath);
    if (!file) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    
    string buffer;
    buffer.reserve(BUFFER_SIZE);
    char chunk[BUFFER_SIZE];

    while (file.read(chunk, sizeof(chunk)) || file.gcount()) {
        buffer.append(chunk, file.gcount());
    }

    
    LexicalAnalyzer lexer(buffer);

    
    vector<Token> tokens = lexer.tokenize();

    
    cout << "Source code: " << endl << buffer << endl << endl;

    
    cout << "Identifiers found by Lexical Analyzer:" << endl;
    printTokens(tokens);

    return 0;
}
