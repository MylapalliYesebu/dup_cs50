#include <stdio.h>

void printCheckSum(int* b1, int* b2, int n) {
    int temp[n];
    int carry = 0;

    // Initialize temp array to 0
    for (int i = 0; i < n; i++) {
        temp[i] = 0;
    }

    // Add the two binary arrays
    for (int i = n - 1; i >= 0; i--) {
        int sum = b1[i] + b2[i] + carry;
        temp[i] = sum % 2;
        carry = sum / 2;
    }

    // Add carry to the result (if there's any overflow)
    for (int i = n - 1; i >= 0; i--) {
        int sum = temp[i] + carry;
        temp[i] = sum % 2;
        carry = sum / 2;
    }

    // Print 1's complement sum
    printf("1's Sum: ");
    for (int i = 0; i < n; i++) {
        printf("%d", temp[i]);
    }
    printf("\n");

    // Calculate checksum (1's complement of the sum)
    printf("Checksum: ");
    for (int i = 0; i < n; i++) {
        printf("%d", 1 - temp[i]);
    }
    printf("\n");
}

int main() {
    int n;
    char dup_bits1[100], dup_bits2[100];
    int bits1[100], bits2[100];

    printf("Enter length of bits: ");
    scanf("%d", &n);

    printf("Enter Subnet 1: ");
    scanf("%s", dup_bits1);

    printf("Enter Subnet 2: ");
    scanf("%s", dup_bits2);

    // Convert input strings to integer arrays
    for (int i = 0; i < n; i++) {
        bits1[i] = dup_bits1[i] - '0';
        bits2[i] = dup_bits2[i] - '0';
    }

    printf("Subnet 1: %s\n", dup_bits1);
    printf("Subnet 2: %s\n", dup_bits2);

    printCheckSum(bits1, bits2, n);

    return 0;
}
