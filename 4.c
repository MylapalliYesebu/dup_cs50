#include <stdio.h>
#include <string.h>

#define is_even_parity 1

// Function to convert binary string to decimal
int binaryTodecimal(char num[]) {
    int i, decimal = 0, mul = 0;
    for (i = strlen(num) - 1; i >= 0; --i, ++mul) {
        decimal += (num[i] - '0') * (1 << mul);
    }
    return decimal;
}

// Function to calculate the parity bit
char Helper(char lst[]) {
    int count = 0, i;
    for (i = 0; i < strlen(lst); i++) {
        if (lst[i] == '1')
            count++;
    }

    if (is_even_parity) {
        return (count % 2 == 0) ? '0' : '1';
    } else {
        return (count % 2 == 0) ? '1' : '0';
    }
}

// Function to generate the Hamming Code
void GetHammingCode(char d[]) {
    char p1, p2, p4, p8;
    char arr1[10] = {d[0], d[2], d[4], d[6]};  // parity bit p1 calculation
    p1 = Helper(arr1);

    char arr2[10] = {d[0], d[1], d[4], d[5]};  // parity bit p2 calculation
    p2 = Helper(arr2);

    char arr3[10] = {d[2], d[3], d[4], d[5]};  // parity bit p4 calculation
    p4 = Helper(arr3);

    char arr4[10] = {d[0], d[1], d[2], d[3]};  // parity bit p8 calculation
    p8 = Helper(arr4);

    char Hcode[12] = {d[0], d[1], d[2], p1, d[3], d[4], p2, d[5], p4, p8, d[6], '\0'};
    printf("Hamming Code For %s is %s\n", d, Hcode);
}

// Function to check and correct Hamming Code
void IsCorrect(char l[]) {
    char p1, p2, p4, p8;
    int error, i;

    char arr1[7] = {l[0], l[2], l[4], l[6], l[8], l[10], '\0'};
    p1 = Helper(arr1);

    char arr2[7] = {l[0], l[1], l[4], l[5], l[8], l[9], '\0'};
    p2 = Helper(arr2);

    char arr3[5] = {l[2], l[3], l[4], l[5], '\0'};
    p4 = Helper(arr3);

    char arr4[5] = {l[0], l[1], l[2], l[3], '\0'};
    p8 = Helper(arr4);

    char arr5[5] = {p8, p4, p2, p1, '\0'};
    error = binaryTodecimal(arr5);

    if (error == 0) {
        printf("Entered Hamming Code is Correct\n");
    } else {
        printf("Entered Hamming Code is Wrong\n");

        // Correct the error bit
        if (l[11 - error] == '1')
            l[11 - error] = '0';
        else
            l[11 - error] = '1';

        printf("Corrected Hamming Code is ");
        for (i = 0; i < 11; i++)
            printf("%c", l[i]);
        printf("\n");
    }
}

int main() {
    char data[8];

    printf("Enter 7-bit Data: ");
    scanf("%s", data);

    GetHammingCode(data);

    char arr[12] = "10101101110"; // Example Hamming code
    IsCorrect(arr);

    return 0;
}
