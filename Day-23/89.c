// WAP to find first non-repeating character
#include <stdio.h>

int main(){
    char str[100];
    printf("Enter the string:\n");
    scanf("%s", str);

    int length=0;
    while (str[length] != 0) length++;

    
    int flag;
    for (int i=0; i <  length; i++){
        flag=1;     // Initially assuming that each character is Non-Repeating Character
        for (int j=0; j < length; j++){     // Comparing each character with a particular character
            if (str[i] == str[j] && (i != j)){  // Checking if same with any character but with not itself
                flag = 0;   // Same character found in string
                break;      // So, no need to further check after first repetition found
            }
        }
        if (flag) {
            printf("First Non-Repeating Character is %c", str[i]);
            return 0;
        }
    }

    printf("There is NO Non-Repeating Character");
    return 0;
}