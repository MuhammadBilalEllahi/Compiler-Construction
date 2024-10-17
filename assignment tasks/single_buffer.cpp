#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

#define BUFFER_SIZE 4096 

int klkl = 1; 


void genToken(char lex[], const char* tokenType) {
    cout << klkl++ << ". Token: " << lex << "      _    Type: " << tokenType << endl;
}


bool isIdentifierChar(char ch) {
    return isalnum(ch) || ch == '_';
}

int main() {
    ifstream file("source_code.cpp");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char buffer[BUFFER_SIZE]; 
    int state = 0; 
    char ch; 
    char lex[100]; 
    int li = 0; 
    int bi = 0; 

    bool inComment = false; 

    
    while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
        int bufferLength = file.gcount(); 

        
        while (bi < bufferLength) {
            ch = buffer[bi];

            
            if (inComment) {
                if (ch == '*' && buffer[bi + 1] == '/') {
                    inComment = false; 
                    bi++; 
                }
                bi++;
                continue;
            }

            switch (state) {
                case 0:
                    if (isalpha(ch) || ch == '_') { 
                        state = 1;
                        lex[li++] = ch;
                    } else if (ch == '/' && buffer[bi + 1] == '/') { 
                        bi++; 
                        while (bi < bufferLength && buffer[bi] != '\n') {
                            bi++; 
                        }
                    } else if (ch == '/' && buffer[bi + 1] == '*') { 
                        inComment = true;
                        bi++; 
                    }
                    break;

                case 1: 
                    if (isIdentifierChar(ch)) {
                        lex[li++] = ch;
                    } else {
                        state = 2;
                        lex[li] = '\0'; 
                    }
                    break;

                case 2: 
                    bi--; 
                    genToken(lex, "ID"); 
                    state = 0; 
                    li = 0; 
                    break;

                default:
                    break;
            }

            bi++; 
        }

        bi = 0; 
    }

    
    if (li > 0) {
        lex[li] = '\0'; 
        genToken(lex, "ID"); 
    }

    file.close(); 
    return 0;
}
