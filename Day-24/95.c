// WAP to Find Longest Word
#include <stdio.h>

int main(){
    char str[100];
    printf("Enter the string:\n");
    fgets(str, sizeof(str), stdin);

    int length=0;
    while (str[length] != 0) length++;

    int words=0, wordsMax=0, wordStartsAt=0, longestWordStartsAt=0;
    for (int i=0; i < length; i++){
        if (str[i] == ' ' || i == length - 1){
            if (words > wordsMax){
                wordsMax = words;
                longestWordStartsAt = wordStartsAt;
            }
            words = 0;
            wordStartsAt=i+1;
        }

        words++;
    }
    
    printf("Longest Word in the given string is: \n");
    for (int i=longestWordStartsAt; i < longestWordStartsAt + wordsMax; i++) printf("%c", str[i]);

    return 0;
}    