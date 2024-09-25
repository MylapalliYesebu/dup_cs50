#include <stdio.h>

int main() {
    int no_of_queries = 4; 
    int storage = 0; 
    int output_pkt_size = 1; 
    int input_pkt_size, bucket_size = 10, size_left;

    for (int i = 0; i < no_of_queries; i++) {
        // Prompt user for input packet size
        printf("Enter the size of the input packet: ");
        scanf("%d", &input_pkt_size);

        // Calculate the available space in the bucket
        size_left = bucket_size - storage;

        // Check if the input packet can fit in the bucket
        if (input_pkt_size <= size_left) {
            storage += input_pkt_size; // Add packets to storage
            printf("Buffer size: %d Out of bucket size: %d\n", storage, bucket_size);
        } else {
            // Fill the bucket to capacity and report packet loss
            int packet_loss = input_pkt_size - size_left;
            storage = bucket_size; // Fill the bucket
            printf("Buffer size: %d Out of bucket size: %d\n", storage, bucket_size);
            printf("Packet loss: %d\n", packet_loss); // Calculate and display packet loss
        }

        // Simulate output at a constant rate
        storage -= output_pkt_size; // Remove one packet sent out
        if (storage < 0) {
            storage = 0; // Prevent negative storage
        }
    }

    return 0;
}


// same in CN lab manuel
/*
#include<stdio.h>

int main() {
    int no_of_queries, storage, output_pkt_size; 
    int input_pkt_size, bucket_size, size_left; 
    storage = 0; 
    no_of_queries = 4; 
    bucket_size = 10; 
    input_pkt_size = 4; 
    output_pkt_size = 1;

    for(int i = 0; i < no_of_queries; i++) {
        size_left = bucket_size - storage;
        if(input_pkt_size <= size_left) {
            storage += input_pkt_size;
            printf("Buffer size: %d Out of bucket size: %d\n", storage, bucket_size);
        } else {
            printf("Packet loss: %d\n", (input_pkt_size - size_left));
            storage = bucket_size;
            printf("Buffer size: %d out of bucket size: %d\n", storage, bucket_size);
        }
        storage -= output_pkt_size;
    }
    return 0;
}
*/
