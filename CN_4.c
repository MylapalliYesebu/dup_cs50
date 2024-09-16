#include <stdio.h>
#include <string.h>

#define is_even_parity 1

// Function to convert binary string to decimal
int binaryToDecimal(char num[]) {
    int decimal = 0, mul = 1;
    int length = strlen(num);

    for (int i = length - 1; i >= 0; --i) {
        decimal += (num[i] - '0') * mul;
        mul *= 2;
    }

    return decimal;
}

// Function to calculate parity bit
char Helper(char bits[]) {
    int count = 0;
    for (int i = 0; i < strlen(bits); i++) {
        if (bits[i] == '1') {
            count++;
        }
    }
    
    if (is_even_parity) {
        return (count % 2 == 0) ? '0' : '1';
    } else {
        return (count % 2 == 0) ? '1' : '0';
    }
}

// Function to generate Hamming code
void GetHammingCode(char d[]) {
    char pl, p2, p4, p8;
    char arr1[4] = {d[0], d[2], d[3], d[5]};
    pl = Helper(arr1);

    char arr2[5] = {d[0], d[1], d[3], d[4], d[6]};
    p2 = Helper(arr2);

    char arr3[4] = {d[3], d[4], d[5]};
    p4 = Helper(arr3);

    char arr4[3] = {d[0], d[1], d[2]};
    p8 = Helper(arr4);

    char Hcode[12] = {d[0], d[1], d[2], p8, d[3], d[4], d[5], p4, d[6], p2, pl};
    printf("Hamming Code For %s is ", d);
    for (int i = 0; i < 11; i++) {
        printf("%c", Hcode[i]);
    }
    printf("\n");
}

// Function to check and correct Hamming code
void IsCorrect(char bits[]) {
    char pl, p2, p4, p8;
    int error;

    char arr1[6] = {bits[0], bits[2], bits[4], bits[6], bits[8], bits[10]};
    pl = Helper(arr1);

    char arr2[6] = {bits[1], bits[3], bits[5], bits[7], bits[9], bits[11]};
    p2 = Helper(arr2);

    char arr3[4] = {bits[4], bits[5], bits[6], bits[7]};
    p4 = Helper(arr3);

    char arr4[3] = {bits[0], bits[1], bits[2]};
    p8 = Helper(arr4);

    char arr5[4] = {p8, p4, p2, pl};
    error = binaryToDecimal(arr5);

    if (error == 0) {
        printf("Entered Hamming Code is Correct\n");
    } else {
        if (bits[11 - error] == '1') {
            bits[11 - error] = '0';
        } else {
            bits[11 - error] = '1';
        }
        printf("Entered Hamming Code is Wrong\n");
        printf("Corrected Hamming Code is ");
        for (int i = 0; i < 12; i++) {
            printf("%c", bits[i]);
        }
        printf("\n");
    }
}

int main() {
    char data[8]; // 7 bits of data + 4 parity bits = 11 bits total
    printf("Enter Data: ");
    scanf("%s", data);

    GetHammingCode(data);

    char arr[12] = "10101001110"; // Example Hamming code with error
    IsCorrect(arr);

    return 0;
}
