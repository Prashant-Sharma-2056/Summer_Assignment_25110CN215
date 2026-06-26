// WAP to find common characters in strings
#include <stdio.h>

void findCommonCharactesr(char str1[], char str2[]){
    int len1=0, len2=0;
    while (str1[len1] != 0) len1++;
    while (str1[len2] != 0) len2++;

    for (int i=0; i < len1; i++){
        for (int j=i; j < len2; j++){
            if (str1[i] == str2[i]){
                printf("%c ", str1[i]);
            }
        }
    }
}

int main(){
    char str1[100], str2[100];
    printf("Enter the first string: \n");
    scanf("%s", str1);
    
    printf("Enter the second string: \n");
    scanf("%s", str2);

    findCommonCharactesr(str1, str2);

    return 0;
}