#include <stdio.h>
#include <string.h>

#define N strlen(g)

char t[28], cs[28], g[28];
int a, e, c, b;

void xor() {
    for (c = 1; c < N; c++) {
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');
    }
}

void crc() {
    for (e = 0; e < N; e++) {
        cs[e] = t[e];
    }

    do {
        if (cs[0] == '1') {
            xor();
        }
        
        for (c = 0; c < N - 1; c++) {
            cs[c] = cs[c + 1];
        }
        
        cs[c] = t[e++];
    } while (e <= a + N - 1);
}

int main() {
    int flag = 0;

    do {
        printf("MENU ----\n");
        printf("1. CRC 12\n2. CRC 16\n3. CRC CCIP\n4. Exit\n\nEnter your option: ");
        scanf("%d", &b);

        switch (b) {
            case 1:
                strcpy(g, "1100000001111");
                break;
            case 2:
                strcpy(g, "11000000000000101");
                break;
            case 3:
                strcpy(g, "10001000000100001");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                continue;
        }

        printf("Enter data: ");
        scanf("%s", t);

        a = strlen(t);

        for (e = a; e < a + N - 1; e++) {
            t[e] = '0';
        }
        t[e] = '\0';

        printf("Generating polynomial: %s\n", g);
        printf("Modified data is: %s\n", t);

        crc();

        printf("Checksum is: %s\n", cs);

        for (e = a; e < a + N - 1; e++) {
            t[e] = cs[e - a];
        }
        t[e] = '\0';

        printf("Final codeword is: %s\n", t);

        printf("Test error detection? (0: Yes, 1: No): ");
        scanf("%d", &flag);

        if (flag == 0) {
            printf("Enter the position where error is to be inserted: ");
            scanf("%d", &e);

            if (e > 0 && e <= a + N - 1) {
                t[e - 1] = (t[e - 1] == '0') ? '1' : '0';
            } else {
                printf("Error position out of bounds.\n");
                continue;
            }

            printf("Erroneous data: %s\n", t);

            crc();

            for (e = 0; (e < N - 1) && (cs[e] != '1'); e++);

            if (e < N - 1) {
                printf("Error detected\n\n");
            } else {
                printf("No error detected\n\n");
            }
        }
    } while (flag != 1);

    return 0;
}
