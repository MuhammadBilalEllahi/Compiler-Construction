// int state = 0;
// char ch;
// char lex[100];
// int li = 0;

// while((ch != buffer[bi]) != EOF){

//     switch (state)
//     {
//     case 0:
//         if(){
//             state = 1;
//             lex[li]=ch;
//             li++;
//         }
//     case 1: 
//         if(isLetter(ch) || isDigit(ch) || '_'){
//             state = 1;
//             lex [li] = ch ;
//             l++;
//         }else{
//             state = 2;
//             lex[li]= '\0';
//         }

//     case 2: 
//         {bi--;
//         genToken(lex,"ID");
//         state = 0;

//         li = 0;
//         break;}
//         b--;
//     default:
//         break;
//     }
// }





// #include <iostream>
// #include <cctype>  //  isalpha and isdigit
// #include <cstring> //  strlen

// using namespace std;

// void genToken(char lex[], const char* tokenType) {
//     cout << "Token: " << lex << ", Type: " << tokenType << endl;
// }

// int main() {
//     char buffer[] = "int var1 = 10; float myVariable = 20.0;";
//     int state = 0;
//     char ch;
//     char lex[100];
//     int li = 0; 
//     int bi = 0; 
//     int bufferLength = strlen(buffer);

//     while (bi < bufferLength) {
//         ch = buffer[bi];

//         switch (state) {
//             case 0:
//                 if (isalpha(ch) || ch == '_') {
//                     state = 1;
//                     lex[li] = ch;
//                     li++;
//                 }
//                 break;

//             case 1:
//                 if (isalnum(ch) || ch == '_') { 
//                     state = 1;
//                     lex[li] = ch;
//                     li++;
//                 } else { 
//                     state = 2;
//                     lex[li] = '\0';
//                 }
//                 break;

//             case 2:
//                 bi--; 
//                 genToken(lex, "ID"); 
//                 state = 0;
//                 li = 0;
//                 break;

//             default:
//                 break;
//         }

//         bi++; 
//     }

    
//     if (li > 0) {
//         lex[li] = '\0';
//         genToken(lex, "ID");
//     }

//     return 0;
// }




#include <iostream>
#include <fstream>  
#include <cctype>   
#include <cstring>  

using namespace std;

#define BUFFER_SIZE 4096 
int klkl = 0; 

// ? No need acording to sir pseudo code
// bool isKeyword(const char* lex) {
//     const char* keywords[] = {"int", "float", "double", "char", "return", "if", "else", "for", "while", "do", "include", "std", "struct", "namespace", "nullptr", "private", "public", "void", "new", "cout", "<<", ">>", "cin"};
//     int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

//     for (int i = 0; i < numKeywords; i++) {
//         if (strcmp(lex, keywords[i]) == 0) {
//             return true; 
//         }
//     }
//     return false;
// }


void genToken(char lex[], const char* tokenType) {
    cout << klkl++ <<". Token: " << lex << "      _    Type: " << tokenType << endl;
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

    
    while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
        int bufferLength = file.gcount(); 
        cout << klkl++ << "-----. "<< bufferLength << " and "<< sizeof(buffer) << endl ;

        cout << "1- " << file.read(buffer, sizeof(buffer));

        while (bi < bufferLength) {
            ch = buffer[bi];
            cout << "BI" << bi << "+" << endl;

            switch (state) {
                case 0:
                    if (isalpha(ch) || ch == '_') { 
                        state = 1;
                        lex[li] = ch;
                        li++;
                    }
                    break;

                case 1:
                    if (isalnum(ch) || ch == '_') { 
                        state = 1;
                        lex[li] = ch;
                        li++;
                    } else { 
                        state = 2;
                        lex[li] = '\0'; 
                    }
                    break;

                case 2:
                    bi--; 
                    // if (isKeyword(lex)) {
                    //     genToken(lex, "KEYWORD"); 
                    // } else {
                        genToken(lex, "ID"); 
                    // }
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

    
    // if (li > 0) {
    //     lex[li] = '\0';
    //     if (isKeyword(lex)) {
    //         genToken(lex, "KEYWORD");
    //     } else {
    //         genToken(lex, "ID");
    //     }
    // }

    file.close(); 
    return 0;
}
