#include <stdio.h>
#include <string.h>

int main() {
    char byts[500], sd, ed, esc = 'E';

    printf("Enter characters to be stuffed: ");
    scanf("%[^\n]", byts); // Read the entire line until a newline character

    // Clear the newline character left in the input buffer
    getchar();

    printf("Enter Starting Delimiter: ");
    scanf(" %c", &sd); // Space before %c to ignore whitespace characters

    printf("Enter Ending Delimiter: ");
    scanf(" %c", &ed); // Space before %c to ignore whitespace characters

    printf("%c ", sd);

    for(int i = 0; i < strlen(byts); i++) {
        if(byts[i] == sd || byts[i] == ed || byts[i] == esc) {
            printf("%c%c", esc, byts[i]);
        } else {
            printf("%c", byts[i]);
        }
    }

    printf(" %c", ed);

    return 0;
}
