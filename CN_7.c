#include <stdio.h>
#include <stdlib.h>

#define no_of_packets 15
#define window_size 5

int main() {
    int p, i = 0, a, w, nac;

    a = no_of_packets;
    w = window_size;

    printf("Transmitting begins...! No of Packets: %d\n", a);

    while (i < a) {
        printf("Sending Packets from %d to %d\n", i + 1, (i + w < a) ? (i + w) : a);

        // Transmit packets in the current window
        for (p = i; p < (i + w) && p < a; p++) {
            printf("Transmitting Packet %d\n", p + 1);
        }

        // Simulate NACK by generating a random number
        nac = rand() % (w + 1); // Random NACK in the range of the window

        // If nac is within the current window, it indicates a NACK for a packet
        if (nac < (i + w) && nac < a) {
            printf("NACK: %d\n", nac + 1);
            printf("Sending Packet: %d\n", nac + 1);
            printf("Ack: %d\n", nac + 2);
        } else {
            printf("Ack: %d\n", (i + w < a) ? (i + w + 1) : (a + 1));
        }

        // Move to the next window
        i += w;
    }
    printf("\nThe packets are transmitted successfully\n");
    return 0;
}
