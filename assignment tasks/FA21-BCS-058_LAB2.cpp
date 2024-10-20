#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

#define BUFFER_SIZE 4096 

int klkl = 1; 

void genToken(char lex[], const char* tokenType) {
    if(tokenType != "ID"){
        cout << klkl++ << ". Token: " << lex << "\nType: " << tokenType << endl;
    }
}

bool isIdentifierChar(char ch) {
    return isalnum(ch) || ch == '_';
}

struct BufferBlock {
    char data[BUFFER_SIZE];
    BufferBlock* next;
};

BufferBlock* loadBuffer(ifstream& file) {
    BufferBlock* block = new BufferBlock;
    file.read(block->data, BUFFER_SIZE);
    if (file.gcount() == 0) {
        delete block;
        return nullptr;
    }
    block->next = nullptr;
    return block;
}

int main() {
    ifstream file("sample.cpp");
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    BufferBlock* head = nullptr;
    BufferBlock* tail = nullptr;
    char lex[100]; 
    int li = 0; 
    int bi = 0; 
    int state = 0; 
    char ch; 

    head = loadBuffer(file);
    tail = head;

    while (tail != nullptr) {
        int bufferLength = file.gcount();

        while (bi < bufferLength) {
            ch = tail->data[bi];

            switch (state) {
                case 0: 
                    if (isalpha(ch) || ch == '_') { 
                        state = 1;
                        lex[li++] = ch;
                    } else if (ch == '/' && tail->data[bi + 1] == '/') { 
                        
                        lex[li++] = ch; 
                        lex[li++] = tail->data[++bi]; 
                        while (bi < bufferLength && tail->data[bi] != '\n') {
                            lex[li++] = tail->data[bi++];
                        }
                        lex[li] = '\0';
                        genToken(lex, "SINGLE-LINE COMMENT");
                        li = 0;
                        state = 0; 
                        continue; 
                    } else if (ch == '/' && tail->data[bi + 1] == '*') { 
                        
                        lex[li++] = ch; 
                        lex[li++] = tail->data[++bi]; 
                        bi++; 
                        while (bi < bufferLength) {
                            lex[li++] = tail->data[bi];
                            if (tail->data[bi] == '*' && tail->data[bi + 1] == '/') {
                                lex[li++] = tail->data[bi + 1]; 
                                lex[li] = '\0';
                                genToken(lex, "MULTI-LINE COMMENT");
                                li = 0;
                                bi += 2; 
                                state = 0; 
                                break;
                            }
                            bi++;
                        }
                        continue; 
                    } else { 
                        
                        state = 2; 
                        lex[li++] = ch; 
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
                    lex[li] = '\0'; 
                    genToken(lex, "ID"); 
                    state = 0; 
                    li = 0; 
                    bi--; 
                    break;

                default:
                    break;
            }

            bi++; 
        }

        
        bi = 0;
        tail = tail->next;
        if (tail == nullptr) {
            tail = loadBuffer(file);
        }
    }

    
    if (li > 0) {
        lex[li] = '\0'; 
        genToken(lex, "ID"); 
    }

    
    while (head != nullptr) {
        BufferBlock* temp = head;
        head = head->next;
        delete temp;
    }

    file.close(); 
    return 0;
}
