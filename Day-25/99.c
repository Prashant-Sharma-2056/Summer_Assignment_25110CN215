// WAP to Sort Names Alphabetically
#include <stdio.h>

int main(){
    char str1[100], str2[100];
    printf("Enter both the words to arrange them alphabetically: \n");
    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = 0, len2 = 0;
    while (str1[len1] != 0) len1++;
    while (str2[len2] != 0) len2++;

    char * first;
    char * second;
    int n;

    if (len1 < len2){
        n = len1;
        first = str1;
        second = str2;
    } else {
        n = len2;
        first = str2;
        second = str1;
    }

    for (int i=0; i < n; i++){
        if (str1[i] < str2[i]){
            first = str1;
            second = str2;
            break;
        }
        else if (str1[i] > str2[i]){
            first = str2;
            second = str1;
            break;
        }
    }

    printf("%s\n", first);
    printf("%s\n", second);

    return 0;
}