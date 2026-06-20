// WAP to count vowels and consonants
#include <stdio.h>

int main(){
    char str[10];
    printf("Enter the string:\n");
    fgets(str, sizeof(str), stdin);
    
    int length=0;
    while (str[length] != 0) length++;
    printf("length: %d", length);

    int vowelsCount = 0, consonantsCount = 0;

    for (int i=0; i < length; i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            vowelsCount++;
        } else consonantsCount++;
    }

    printf("Vowels: %d, Consonants: %d", vowelsCount, consonantsCount);

    return 0;
}