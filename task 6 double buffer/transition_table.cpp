#include "iostream"



enum COL {
    L,D,U,NLDU, A,R,T // literal, Digit, Underscore, Not(literal, Digit, Underscore), Accepting state , Retracting STate, Token
}   
enum S {
    F,T //true , false
}
enum LexicalUnit {
    N, IDENTIFIER, PUNCTUATION, KEYWORD, LITERALS, //total 7
}

// E.G : 

State | l | d | _ | !{l|d|_} | A | R | T |
 0    | 1 | - | 1 | -        | F | F | N |
 1    | 1 | 1 | 1 | -        | F | F | N |
 2    | 1 | - | 1 | -        | F | - | - |
// { 
    // {1,-1,1,-1, F,F,N}
    // {1,1,1,2,F,F,N}
    // {0,0,0,0,T,T,ID}
// }




int main(){

    char lex[100];
    int li = 0;
    state == 0;

    while((ch == buffer[bi]) !== EOF){
        if(!TT[state][A]){
            state = TT[state]
        }
    }

}
