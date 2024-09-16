#include <stdio.h>
#include <string.h>

int main() {
    char bits[500];
    int count = 0;

    printf("Enter the bits to be stuffed: ");
    scanf("%s", bits); // No & needed for string input

    printf("01111110"); // Frame start delimiter

    for(int i = 0; i < strlen(bits); i++) {
        if(bits[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        printf("%c", bits[i]);

        if(count == 5) {
            printf("0");
            count = 0;
        }
    }

    printf("01111110"); // Frame end delimiter

    return 0;
}
