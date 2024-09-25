#include <stdio.h>
#include <string.h>
#define N strlen(g)  // Define N as the length of the generator polynomial

char t[28], cs[28], g[28];  // Arrays for the data, checksum, and generator polynomial
int a, e, c, b;

void xor() {
    for(c = 1; c < N; c++)
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');  // Perform XOR between cs and g
}

void crc() {
    for(e = 0; e < N; e++) cs[e] = t[e];  // Initialize cs with the first part of t
    do {
        if(cs[0] == '1') xor();  // Perform XOR if the first bit is 1
        for(c = 0; c < N - 1; c++) cs[c] = cs[c + 1];  // Shift left
        cs[c] = t[e++];  // Bring in the next bit
    } while(e <= a + N - 1);
}

int main() {
    int flag = 0;
    do {
        printf("--MENU ----\n");
        printf("1. CRC-12\n2. CRC-16\n3. CRC-CCIP\n4. Exit\n\nEnter your option: ");
        scanf("%d", &b);
        switch(b) {
            case 1: strcpy(g, "1100000001111"); break;  // CRC-12
            case 2: strcpy(g, "11000000000000101"); break;  // CRC-16
            case 3: strcpy(g, "10001000000100001"); break;  // CRC-CCIP
            case 4: return 0;  // Exit
        }

        printf("Enter data: ");
        scanf("%s", t);
        printf("Generating polynomial: %s\n", g);
        a = strlen(t);

        for(e = a; e < a + N - 1; e++)  // Append N-1 zeros to the data
            t[e] = '0';
        t[e] = '\0';

        printf("Modified data is: %s\n", t);
        crc();  // Calculate the CRC
        printf("Checksum is: %s\n", cs);

        for(e = a; e < a + N - 1; e++)  // Append checksum to data
            t[e] = cs[e - a];
        t[e] = '\0';

        printf("Final codeword is: %s\n", t);
        printf("Test error detection (0: yes, 1: no)? ");
        scanf("%d", &e);

        if(e == 0) {
            do {
                printf("Enter the position where error is to be inserted: ");
                scanf("%d", &e);
            } while(e <= 0 || e > a + N - 1);
            t[e - 1] = (t[e - 1] == '0') ? '1' : '0';  // Flip the bit
            printf("Erroneous data: %s\n", t);
        }

        crc();  // Recalculate CRC on erroneous data
        for(e = 0; (e < N - 1) && (cs[e] != '1'); e++);
        if(e < N - 1)
            printf("Error detected\n\n");
        else
            printf("No error detected\n\n");

    } while(flag != 1);

    return 0;
}
