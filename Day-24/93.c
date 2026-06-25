// WAP to check String Rotation
#include <stdio.h>

int isSameString(char word1[], char word2[]){
    int length1=0, length2=0;
    while (word1[length1] != 0) length1++;
    while (word2[length2] != 0) length2++;

    if (length1 != length2) return 0;

    for (int i=0; i < length1; i++){
        if (word1[i] != word2[i]){
            return 0;
        }
    }

    return 1;
}

void rotateStringRightBy1(char str[]){
    int len=0;
    while (str[len] != 0) len++;

    char last = str[len-1];
    for (int i=0; i < len - 1; i++){
        str[len - i - 1] = str[len - i - 2];
    }
    str[0] = last;
}

int isRotatedString(char word1[], char word2[]){
    int len=0;
    while (word1[len] != 0) len++;

    for (int i=0; i < len; i++){
        if (!isSameString(word1, word2)){
            rotateStringRightBy1(word2);
        } else {
            return 1;
        }
    }

    return 0;
}

int main(){
    char str1[100], str2[100];
    printf("Enter the string in lowercase:\n");
    // fgets(str1, sizeof(str1), stdin);
    scanf("%s", str1);
    
    printf("Enter the string in lowercase:\n");
    // fgets(str2, sizeof(str2), stdin);
    scanf("%s", str2);

    if (isRotatedString(str1, str2)) printf("Strings are ROATATED STRINGS");
    else printf("Strings are NOT ROTATED Strings");


    return 0;
}    