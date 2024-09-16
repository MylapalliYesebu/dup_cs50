#include <stdio.h>

int main() {
    int no_of_queries = 4; // Number of queries or incoming packets
    int storage = 0;      // Current storage in the bucket
    int bucket_size = 10; // Maximum capacity of the bucket
    int input_pkt_size = 4; // Size of incoming packets
    int output_pkt_size = 1; // Size of packets leaked out per time unit
    int size_left; // Space left in the bucket
    int i;

    printf("Bucket Size: %d\n", bucket_size);
    printf("Output Packet Size: %d\n", output_pkt_size);
    
    for(i = 0; i < no_of_queries; i++) {
        // Simulating the addition of a new packet
        size_left = bucket_size - storage;

        // Handling the incoming packet
        if(input_pkt_size <= size_left) {
            storage += input_pkt_size;
            printf("Added packet of size %d. Buffer size: %d, Out of bucket size: %d\n", 
                input_pkt_size, storage, bucket_size);
        } else {
            printf("Packet of size %d dropped. Buffer size: %d, Out of bucket size: %d\n",
                input_pkt_size, storage, bucket_size);
            // Packet loss handling
            storage = bucket_size; // Bucket is full
        }

        // Simulating leakage of packets
        storage -= output_pkt_size;
        if(storage < 0) {
            storage = 0;
        }

        printf("After leakage, Buffer size: %d, Out of bucket size: %d\n", 
            storage, bucket_size);
    }

    return 0;
}
