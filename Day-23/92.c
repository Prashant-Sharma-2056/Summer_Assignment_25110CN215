// WAP to Find Maximum Occuring Character
#include <stdio.h>

int main(){
    char str[100];
    printf("Enter the string:\n");
    scanf("%s", str);

    int length=0;
    while (str[length] != 0) length++;

    char ch;
    int frequency = 0, frequencyMax = 0;
    for (int i=0; i < length; i++){
        frequency=1;
        for (int j=0; j < length; j++){     // Comparing each character with a particular character
            if (str[i] == str[j] && (i != j)){  // Checking if same with any character but with not itself
                frequency++;    // Same character found in string
            }
        }
        if (frequency > frequencyMax){
            frequencyMax = frequency;
            ch = str[i];
        }
    }

    printf("Maximum Frequency Character is %c with %d occurances", ch, frequencyMax);
    return 0;
}