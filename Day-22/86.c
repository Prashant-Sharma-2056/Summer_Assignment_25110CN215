// WAP to count number of words in a sentence
#include <stdio.h>

int main(){
    char str[100];
    printf("Enter the string:\n");
    fgets(str, sizeof(str), stdin);

    int length=0;
    while (str[length] != 0) length++;

    int spaces=0;
    for (int i=0; i < length; i++){
        if (str[i] == ' ') spaces++;
    }

    printf("There are %d words in the given sentences", spaces + 1);

    return 0;
}    