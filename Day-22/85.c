// WAP to check palindrome string
#include <stdio.h>

int palindromeCheckString(char * str, int size){
    for (int i=0; i < size; i++){
        if (str[i] != str[size - 1 - i]) return 0; 
    } 

    return 1;
}

int main(){
    char str[50];
    printf("Enter the string to check for palindrome:\n");
    scanf("%s", str);

    int length=0;
    while (str[length] != 0) length++;

    if (palindromeCheckString(str, length)) printf("PALINDROM String");
    else printf("NOT Palindrome");

    return 0;
}