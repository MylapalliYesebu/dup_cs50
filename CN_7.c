#include <stdio.h>
#include <stdlib.h>

#define NO_OF_PACKETS 15
#define WINDOW_SIZE 5

int main() {
    int i = 0, p, nac, ack;
    int a = NO_OF_PACKETS;
    int w = WINDOW_SIZE;

    printf("Transmitting begins...! No of Packets: %d\n", a);

    while (i < a) {
        // Display current window
        printf("Sending Packets from %d to %d\n", i, (i + w - 1) < a ? (i + w - 1) : (a - 1));
        
        // Send packets in the current window
        for (p = i; p < (i + w) && p < a; p++) {
            printf("Transmitting Packet %d\n", p);
        }

        // Simulate acknowledgment or negative acknowledgment
        nac = rand() % (w + 1);
        
        if (nac < WINDOW_SIZE) {
            printf("NACK: %d\n", nac);
            printf("Retransmitting Packet: %d\n", nac);
            // Optionally simulate retransmission
        } else {
            // Simulate acknowledgment for all packets in the current window
            printf("Ack: %d\n", i + w);
        }

        // Slide the window
        i += w;
    }

    // Final acknowledgment for the last window
    if (i >= a) {
        printf("Ack: %d\n", a);
    }

    return 0;
}
