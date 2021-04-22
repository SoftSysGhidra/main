/*
* Crackme created by Caitlin Coffey and Zoe McGinnis 
* 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void format(char* arg) {
    printf("command format: %s <password>\n Try again!\n", arg);
    exit(0);
}

int main(int argc, char **argv) {
    size_t length;
    if (argc == 2) {
        length = strlen(argv[1]);
        if (length == 5) {
            if ((argv[1][4] == 't') 
                && (argv[1][0] == 'b')
                && (argv[1][2] == 'r')
                && (argv[1][1] == 'o')
                && (argv[1][3] == 'a')) {
                printf("Very nice!\n Pass: {%s}\n", argv[1]);
            }
            else {format(argv[0]);}
        }
        else {format(argv[0]);}
    }
    else {format(argv[0]);}
    return 0;
}
