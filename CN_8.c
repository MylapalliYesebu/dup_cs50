#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_PACKETS 5

int main() {
    int i, ack, timeout, resend;
    
    // Initialize random seed
    srand(time(NULL));

    printf("The No of Packets are: %d\n", TOTAL_PACKETS);

    for (i = 1; i <= TOTAL_PACKETS; i++) {
        printf("The Packet Sent is %d\n", i);

        // Simulate packet acknowledgment or NACK with a timeout
        timeout = rand() % 2;  // 0 for timeout, 1 for acknowledgment

        if (timeout == 1) {
            ack = rand() % 2;  // 0 for NACK, 1 for ACK
            if (ack == 1) {
                printf("Ack number: %d\n", i + 1);
            } else {
                printf("NACK number: %d\n", i + 1);
                // Resend packet
                printf("Resending Packet %d\n", i);
                i--;  // Decrement to resend the current packet
            }
        } else {
            printf("Time Out..! Resend Packet %d\n", i);
            // Resend packet
            i--;  // Decrement to resend the current packet
        }
    }

    printf("All packets sent and acknowledged.\n");

    return 0;
}
