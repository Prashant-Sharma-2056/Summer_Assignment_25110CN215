// WAP to Sort Words By Length
#include <stdio.h>

void sortStringsByLength(char str1[], char str2[], char * first, char * second){
    int len1 = 0, len2 = 0;
    while (str1[len1] != 0) len1++;
    while (str2[len2] != 0) len2++;

    printf("SORTED STRINGS:\n");
    if (len1 < len2){
        printf("%s\n", str1);
        printf("%s\n", str2);
    } else {
        printf("%s\n", str2);
        printf("%s\n", str1);
    }
}

int main(){
    char str1[100], str2[100];
    printf("Enter both the words to arrange them alphabetically: \n");
    scanf("%s", str1);
    scanf("%s", str2);

    char * first; char * second;
    sortStringsByLength(str1, str2, first, second);

    return 0;
}