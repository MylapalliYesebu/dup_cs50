#include <stdio.h>
#include <string.h>

#define CRC12_POLY "1100000001111"
#define CRC16_POLY "11000000000000101"
#define CRC_CCITT_POLY "10001000000100001"

#define CRC12_LEN 13
#define CRC16_LEN 17
#define CRC_CCITT_LEN 17

void xorOperation(char *remainder, const char *polynomial, int polyLen) {
    for (int i = 0; i < polyLen; i++) {
        remainder[i] = (remainder[i] == polynomial[i]) ? '0' : '1';
    }
}

void crc(char *data, const char *polynomial, char *checksum, int polyLen) {
    int dataLen = strlen(data);
    int totalLen = dataLen + polyLen - 1;

    // Append zeros to the data
    char modifiedData[totalLen + 1];
    strcpy(modifiedData, data);
    for (int i = dataLen; i < totalLen; i++) {
        modifiedData[i] = '0';
    }
    modifiedData[totalLen] = '\0';

    // Initialize remainder with the modified data
    char remainder[totalLen + 1];
    strncpy(remainder, modifiedData, totalLen);
    remainder[totalLen] = '\0';

    // Perform CRC calculation
    for (int i = 0; i < dataLen; i++) {
        if (remainder[i] == '1') {
            xorOperation(remainder + i, polynomial, polyLen);
        }
    }

    // Copy the remainder to checksum
    strncpy(checksum, remainder + dataLen, polyLen - 1);
    checksum[polyLen - 1] = '\0';
}

int main() {
    int option;
    char data[100], checksum[20];

    do {
        printf("--MENU ----\n");
        printf("1. CRC-12\n2. CRC-16\n3. CRC-CCITT\n4. Exit\n\nEnter your option: ");
        scanf("%d", &option);

        if (option == 4) break;

        printf("Enter data: ");
        scanf("%s", data);

        switch (option) {
            case 1:
                printf("Generating polynomial: %s\n", CRC12_POLY);
                crc(data, CRC12_POLY, checksum, CRC12_LEN);
                printf("Checksum is: %s\n", checksum);
                printf("Final codeword is: %s%s\n", data, checksum);
                break;
            case 2:
                printf("Generating polynomial: %s\n", CRC16_POLY);
                crc(data, CRC16_POLY, checksum, CRC16_LEN);
                printf("Checksum is: %s\n", checksum);
                printf("Final codeword is: %s%s\n", data, checksum);
                break;
            case 3:
                printf("Generating polynomial: %s\n", CRC_CCITT_POLY);
                crc(data, CRC_CCITT_POLY, checksum, CRC_CCITT_LEN);
                printf("Checksum is: %s\n", checksum);
                printf("Final codeword is: %s%s\n", data, checksum);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

        int testError;
        printf("Test error detection (0=yes, 1=no)?: ");
        scanf("%d", &testError);

        if (testError == 0) {
            int errorPos;
            printf("Enter the position where error is to be inserted: ");
            scanf("%d", &errorPos);

            int dataLen = strlen(data);
            if (errorPos < 0 || errorPos >= dataLen) {
                printf("Invalid position.\n");
                continue;
            }

            // Insert error
            data[errorPos] = (data[errorPos] == '0') ? '1' : '0';
            printf("Erroneous data: %s\n", data);

            // Recalculate CRC
            char erroneousChecksum[20];
            switch (option) {
                case 1:
                    crc(data, CRC12_POLY, erroneousChecksum, CRC12_LEN);
                    break;
                case 2:
                    crc(data, CRC16_POLY, erroneousChecksum, CRC16_LEN);
                    break;
                case 3:
                    crc(data, CRC_CCITT_POLY, erroneousChecksum, CRC_CCITT_LEN);
                    break;
            }

            // Check if error is detected
            if (strcmp(erroneousChecksum, "0") != 0) {
                printf("Error detected\n");
            } else {
                printf("No error detected\n");
            }
        }
    } while (option != 4);

    return 0;
}
