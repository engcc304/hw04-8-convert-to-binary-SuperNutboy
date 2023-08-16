/*
    จงแปลงเลขฐาน 16 ที่รับมาจากผู้ใช้ให้กลายเป็นเลขฐาน 2
    
    Test case:
        User input :
            FB
    Output:
        11111011

    Test case:
        User input :
            19
    Output:
        11001
*/
#include <stdio.h>
#include <string.h>

int hexToDecimal(char hexDigit) {
    if (hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0';
    } else if (hexDigit >= 'A' && hexDigit <= 'F') {
        return 10 + (hexDigit - 'A');
    } else if (hexDigit >= 'a' && hexDigit <= 'f') {
        return 10 + (hexDigit - 'a');
    }
    return -1;
}

int main() {
    char hex[10];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int decimal = 0;
    int length = strlen(hex);
    int base = 1;

    for (int i = length - 1; i >= 0; i--) {
        decimal += hexToDecimal(hex[i]) * base;
        base *= 16;
    }

    int binary[40];
    int index = 0;
    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }

    printf("Binary equivalent: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}