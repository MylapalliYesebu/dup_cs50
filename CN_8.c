#include<stdio.h>
#include<stdlib.h>
int main() // Syntax fix: added closing parenthesis
{
    int i, n, r, a;
    n = 5; // Number of packets is fixed to 5
    printf("The No of Packets are: %d\n", n);

    for (i = 1; i <= n; i++) // Loop for each packet
    {
        printf("The Packet Sent is %d\n", i);

        r = rand() % 2; // Simulating random transmission (successful or not)

        if (r == 1) // Successful transmission
        {
            a = rand() % 2; // Simulating random ACK or NACK
            if (a == 1) // If acknowledgment is received (ACK)
            {
                printf("Ack number: %d\n", i + 1); // ACK for the next packet
            }
            else // If no acknowledgment (NACK)
            {
                printf("NACK number: %d\n", i + 1); // NACK, resend the same packet
                i--; // Decrement to resend the same packet
            }
        }
        else // If transmission failure (timeout)
        {
            printf("Time Out..! Resend Packet\n");
            i--; // Decrement to resend the same packet
        }
    }
    printf("Packets are transmitted successfully");
    return 0;
}
