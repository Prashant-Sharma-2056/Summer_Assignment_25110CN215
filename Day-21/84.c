// WAP to convert lowercase to uppercase
#include <stdio.h>

int main(){
    char str[10];
    printf("Enter the string:\n");
    scanf("%s", str);
    
    int length=0;
    while (str[length] != 0) length++;

    for (int i=0; i < length; i++) {
        if (str[i] >= 97 && str[i] <= 122) str[i] -= 32;
    }

    printf("%s", str);

    return 0;
}