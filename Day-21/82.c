// WAP to reverse a string
#include <stdio.h>

int main(){
    char str[10];
    printf("Enter the string:\n");
    scanf("%s", str);
    
    int length=0;
    while (str[length] != 0) length++;

    char x;
    for (int i=0; i < length/2; i++){
        x = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = x;
    }

    printf("%s", str);

    return 0;
}