#include <stdio.h>
#include <string.h>

int main() {
    char byts[500], sd, ed, esc = 'E'; // Define the escape character

    // Clear the input buffer
    fflush(stdin);

    // Input the data to be stuffed
    printf("Enter characters to be stuffed: ");
    fgets(byts, sizeof(byts), stdin); // Use fgets to read the entire line
    byts[strcspn(byts, "\n")] = '\0'; // Remove newline character if present

    // Input the starting delimiter
    printf("Enter Starting Delimiter: ");
    sd = getchar(); // Read the starting delimiter
    getchar(); // Clear the newline character left by getchar()

    // Input the ending delimiter
    printf("Enter Ending Delimiter: ");
    ed = getchar(); // Read the ending delimiter
    getchar(); // Clear the newline character left by getchar()

    // Print the starting delimiter
    printf("%c", sd);

    // Iterate through the input string
    for (int i = 0; i < strlen(byts); i++) {
        // If a character matches the starting or ending delimiter or the escape character, print the escape character first
        if (byts[i] == sd || byts[i] == ed || byts[i] == esc) {
            printf("%c", esc); // Insert escape character before the delimiter or escape character
        }
        // Print the current character (whether stuffed or not)
        printf("%c", byts[i]);
    }

    // Finally, print the ending delimiter
    printf("%c", ed);

    return 0;
}
