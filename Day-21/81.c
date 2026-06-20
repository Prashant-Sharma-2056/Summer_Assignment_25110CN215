// WAP to find string length without strlen()
#include <stdio.h>

int main(){
    char str[10];
    printf("Enter the string:\n");
    scanf("%s", str);

    int length=0;
    while (str[length] != 0) length++;

    printf("String Length: %d", length);

    return 0;
}