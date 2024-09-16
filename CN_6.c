#include <stdio.h>

int main() {
    int windowSize, sent = 0, ack, i;

    printf("Enter window size: ");
    scanf("%d", &windowSize);

    while (1) {
        // Send frames within the window
        for (i = 0; i < windowSize; i++) {
            printf("Frame %d has been transmitted.\n", sent);
            sent++;
            // If the number of frames exceeds the window size, break out of the loop
            if (sent % windowSize == 0) {
                break;
            }
        }

        // Prompt user for acknowledgment
        printf("\nPlease enter the last Acknowledgement received: ");
        scanf("%d", &ack);

        // Check if the acknowledgment received is within the window size
        if (ack >= windowSize) {
            // Slide the window
            sent = ack;
        } else {
            // If acknowledgment is less than window size, retransmit frames
            printf("Retransmitting frames starting from %d.\n", ack);
            sent = ack;
        }

        // Exit condition to stop the loop (you can add a condition or a command to exit)
        if (sent >= 20) { // Example condition: stop after 20 frames have been sent
            break;
        }
    }

    return 0;
}
