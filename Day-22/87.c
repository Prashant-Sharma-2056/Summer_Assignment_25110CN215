// WAP to check character frequenct
#include <stdio.h>

int main(){
    char str[50], character;
    printf("Enter the character to check it's frequency in string: \n");
    scanf("%c", &character);

    printf("Enter the string to check for character frequency:\n");
    scanf("%s", str);

    int length=0, frequency=0;
    while (str[length] != 0) length++;

    for (int i=0; i < length; i++) if (str[i] == character) frequency++;

    printf("There is %d occurances of %c in %s", frequency, character, str);


    return 0;
}