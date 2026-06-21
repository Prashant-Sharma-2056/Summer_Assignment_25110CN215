// WAP to remove spaces from the string
#include <stdio.h>

int main(){
    char str[100];
    printf("Enter the string:\n");
    fgets(str, sizeof(str), stdin);

    int length=0;
    while (str[length] != 0) length++;

    int spaces=0;
    for (int i=0; i < length - spaces; i++){
        if (str[i] == ' '){
            spaces++;
            for (int j=i; j < length - spaces + 1; j++) str[j] = str[j+1];
        }
    }
    
    printf("%s", str);

    return 0;
}    