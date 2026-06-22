// WAP to check Anagram Strings.
#include <stdio.h>

int anagramStrings(char word1[], char word2[]){
    int length1=0, length2=0;
    while (word1[length1] != 0) length1++;
    while (word2[length2] != 0) length2++;

    if (length1 != length2) return 0;

    int flag;
    for (int i=0; i < length1; i++){
        flag=0;
        for (int j=0; j < length2; j++){
            if (word1[i] == word2[j]){
                flag = 1;
                break;
            }
        }

        if (!flag) return 0;
    }

    return 1;
}

int main(){
    char str1[100], str2[100];
    printf("Enter the first word: \n");
    scanf("%s", str1);
    
    printf("Enter the second word: \n");
    scanf("%s", str2);

    if (anagramStrings(str1, str2)) printf("Given strings are ANAGRAM Strings");
    else printf("Given Strings are NOT ANAGRAM Strings");    

    return 0;
}