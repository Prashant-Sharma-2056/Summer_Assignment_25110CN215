// WAP to Compress Strings
#include <stdio.h>

void compressString(char str[]){
    int length=0;
    while (str[length] != 0) length++;

    char count = '1', compStr[100];
    int compLen = 0;
    compStr[0] = str[0];
    for (int i=1; i < length; i++){
        if (str[i] == str[i-1]){
            count++;
        } else {
            compLen++;
            compStr[compLen] = count;
            compLen++;
            compStr[compLen] = str[i];
            count = '1';
        }

        // printf("i=%d; String: %s, Comp: %s, count: %c, complen: %d \n", i, str, compStr, count, compLen);
    }

    compLen++;
    compStr[compLen] = count;
    compLen++;
    compStr[compLen] = 0;

    printf("Compressed String: %s", compStr);
}

int main(){
    char str[100];
    printf("Enter the string:\n");
    scanf("%s", str);

    compressString(str);
    // char x = '5';
    // x++;
    // printf("%c", x);
    
    return 0;
}    