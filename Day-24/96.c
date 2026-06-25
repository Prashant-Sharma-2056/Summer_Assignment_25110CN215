// WAP to Remove Duplicate Characters
#include <stdio.h>

int removeDuplicateChars(char str[]){
    int len=0, count=0;
    while (str[len] != 0) len++;

    for (int i=0; i < len - count - 1; i++){
        if (str[i] == str[i + 1]){
            count++;
            for (int j = i; j < len - count; j++){
                str[j] = str[j + 1];
            }
            i=0;
        }

        // printf("i = %d, str = %s, count = %d\n", i, str, count);
    }

    return len - count; // This is the length of the new string after removing duplicates
}

int main(){
    char str[100];
    printf("Enter the string:\n");
    scanf("%s", str);

    for (int i = 0; i < removeDuplicateChars(str); i++) printf("%c", str[i]);

    return 0;
}