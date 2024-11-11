#include <stdio.h>
#include <string.h>

int main() {
    char bits[500];
    int count = 0;

    printf("Enter the bits to be stuffed: ");
    scanf("%s", bits); // No & needed for string input

    printf("01111110 "); // Frame start delimiter

    int length = strlen(bits);
    for(int i = 0; i < length; i++) {
        if(bits[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        printf("%c", bits[i]);

        if(count == 5) {
            printf("0");
            count = 0; // Reset count after inserting stuffed bit
        }
    }

    // If the last bit sequence ends with exactly five 1's, we need to add an extra 0
    if(count == 5) {
        printf("0");
    }

    printf(" 01111110"); // Frame end delimiter

    return 0;
}
