#include <stdio.h>

int main() {
    int window_size, sent = 0, ack, i;

    // Input the window size
    printf("Enter window size: ");
    scanf("%d", &window_size);

    // Main loop to simulate frame transmission
    while (1) {
        // Send frames within the window size
        for (i = 0; i < window_size; i++) {
            printf("Frame %d has been transmitted.\n", sent);
            sent++;

            // Check if the last frame has been sent
            if (sent == window_size)
                break;
        }

        // Prompt for the last acknowledgment received
        printf("\nPlease enter the last Acknowledgement received: ");
        scanf("%d", &ack);

        // If acknowledgment is for the last frame, end transmission
        if (ack >= window_size) {
            printf("All frames have been acknowledged. Transmission complete.\n");
            break;
        } else {
            // Go back to the frame that needs to be resent
            sent = ack;
        }
    }

    return 0;
}
