#include <stdio.h>
#include <stdlib.h>

int main (){
    
    int chSize = 2;
    char* x = (char *)malloc(sizeof(char)*chSize);
    char character;
    int i = 0;

    printf("\nInitial allocated size: %d bytes", chSize);
    printf("\nSize : %lu", sizeof(*x));
    printf("\nEnter your name: ");
    // scanf("%s", &x);

    
    while (character != '\n' ){
        character = getchar();
        // if(character == '\n'){ return 0;}

            printf("\t-> %c", character);
            printf("\t Initial allocated size: %d bytes\n", chSize);

        if (i > chSize -1 ){
            chSize += 2 ;
            x = realloc(x,chSize);
            printf("\t-> %c", character);
            printf("\t Initial allocated size: (Exceeded) %d bytes\n", chSize);
        }
        x[i] = character;
        i++;
        

    }
    x[i] = '\0';
    printf("\nName is: %s \n", x);
        free(x);

}

