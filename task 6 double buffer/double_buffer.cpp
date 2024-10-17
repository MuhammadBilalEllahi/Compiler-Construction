// #include <iostream>
// #include <fstream>
// #include <cctype>
// #include <cstring>

// using namespace std;

// #define BUFFER_SIZE 4096 
// int klkl = 1; 

// void genToken(char lex[], const char* tokenType) {
//     cout << klkl++ <<". Token: " << lex << "      _    Type: " << tokenType << endl;
// }

// int main() {
//     ifstream file("source_code.cpp"); 
//     if (!file.is_open()) {
//         cout << "Error opening fiel!" << endl;
//         return 1;
//     }

//     char buffer[BUFFER_SIZE]; 
//     char bufferTwo[BUFFER_SIZE]; 

//     int state = 0;
//     char ch;
    
//     int bi = 0;    
//     int biTwo = 0;    

//     char lex[100]; 
//     int li = 0;    

//     bool activateBufferTwo = false;
    
//     while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
//         int bufferLength = file.gcount(); 
//         // cout << klkl++ << "-----. "<< bufferLength << " and "<< sizeof(buffer) << endl ;

//         // cout << "1- " << file.read(buffer, sizeof(buffer));
 
//         while (bi < bufferLength) {

//             if(bi == sizeof(buffer) ){
//                 bi = 0;
//                 activateBufferTwo = true;
//             }else if(biTwo == sizeof(bufferTwo)){
//                 biTwo = 0;
//                 activateBufferTwo = false;
//             }
            
//             // cout << "BI" << bi << "+" << endl;

//             switch (state) {
//                 case 0:
//                     if (isalpha(ch) || ch == '_') { 
//                         state = 1;
//                         lex[li] = ch;
//                         li++;
//                     }else if (ch == '"' ){
//                         state = 1;
//                         lex[li] = ch;
//                         li++;
//                     }
//                     break;

//                 case 1:
//                     if (isalnum(ch) || ch == '_') { 
//                         state = 1;
//                         lex[li] = ch;
//                         li++;
//                     } else { 
//                         state = 2;
//                         lex[li] = '\0'; 
//                     }
//                     break;

//                 case 2:
//                     bi--; 
//                     // if (isKeyword(lex)) {
//                     //     genToken(lex, "KEYWORD"); 
//                     // } else {
//                         genToken(lex, "ID"); 
//                     // }
//                     state = 0;
//                     li = 0; 
//                     break;

//                 default:
//                     break;
//             }

//             bi++; 
//         }

        
//         bi = 0;
//     }

    
//     // if (li > 0) {
//     //     lex[li] = '\0';
//     //     if (isKeyword(lex)) {
//     //         genToken(lex, "KEYWORD");
//     //     } else {
//     //         genToken(lex, "ID");
//     //     }
//     // }

//     file.close(); 
//     return 0;
// }



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

int main() {
    ifstream file("source_code.cpp");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char bufferOne[BUFFER_SIZE];
    char bufferTwo[BUFFER_SIZE];

    int state = 0;
    char ch;

    int bi = 0;     
    int li = 0;     
    char lex[100];  

    bool isBufferOneActive = true;  
    bool inStringLiteral = false;   

    
    file.read(bufferOne, sizeof(bufferOne));

    while (!file.eof() || bi < file.gcount()) {
        char* currentBuffer = isBufferOneActive ? bufferOne : bufferTwo;  

        int bufferLength = file.gcount();  

        while (bi < bufferLength) {
            ch = currentBuffer[bi];

            switch (state) {
                case 0:  
                    if (isalpha(ch) || ch == '_') {  
                        state = 1;
                        lex[li++] = ch;
                    } else if (ch == '"') {  
                        state = 1;
                        inStringLiteral = true;
                        lex[li++] = ch;
                    }
                    break;

                case 1:  
                    if (inStringLiteral) {
                        lex[li++] = ch;
                        if (ch == '"') {  
                            lex[li] = '\0';  
                            genToken(lex, "STRING_LITERAL");
                            state = 0;
                            li = 0;
                            inStringLiteral = false;  
                        }
                    } else {
                        if (isalnum(ch) || ch == '_') {  
                            lex[li++] = ch;
                        } else {  
                            lex[li] = '\0';  
                            genToken(lex, "ID");
                            state = 0;
                            li = 0;
                            bi--;  
                        }
                    }
                    break;

                default:
                    break;
            }

            bi++;
        }

        bi = 0;

       
        isBufferOneActive = !isBufferOneActive;

        if (isBufferOneActive) {
            file.read(bufferOne, sizeof(bufferOne));
        } else {
            file.read(bufferTwo, sizeof(bufferTwo));
        }
    }

    file.close();
    return 0;
}
