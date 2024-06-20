#include <stdio.h>
#include <stdbool.h>

void convert_to_key_press(char byte) {
    switch (byte) {
        case 0x08: printf("[Backspace]"); break;
        case 0x09: printf("[Tab]"); break;
        case 0x0A: printf("[Line Feed]"); break;
        case 0x0D: printf("[Carriage Return]"); break;
        case 0x1B: printf("[Escape]"); break;
        case 0x20: printf("[Space]"); break;
        case 0x7F: printf("[Delete]"); break;
        default:
            if (byte >= 32 && byte <= 126) {
                printf("%c", byte);
            } else {
                printf("[0x%02X]", (unsigned char)byte);
            }
            break;
    }
}

void process_and_print(char arr[], int length) {
    for (int i = 0; i < length; i++) {
        convert_to_key_press(arr[i]);
    }
    printf("\n");
}

int main() {
    char peer0_13[] = { /* Packet 45 */
    0x66 };
    char peer0_14[] = { /* Packet 47 */
    0x74 };
    char peer0_15[] = { /* Packet 49 */
    0x5f };
    char peer0_16[] = { /* Packet 51 */
    0x77 };
    char peer0_17[] = { /* Packet 53 */
    0x61 };
    char peer0_18[] = { /* Packet 55 */
    0x6e };
    char peer0_19[] = { /* Packet 57 */
    0x64 };
    char peer0_20[] = { /* Packet 59 */
    0x72 };
    char peer0_21[] = { /* Packet 61 */
    0x7f };
    char peer0_22[] = { /* Packet 63 */
    0x7f };
    char peer0_23[] = { /* Packet 65 */
    0x7f };
    char peer0_24[] = { /* Packet 67 */
    0x4e };
    char peer0_25[] = { /* Packet 69 */
    0x44 };
    char peer0_26[] = { /* Packet 71 */
    0x52 };
    char peer0_27[] = { /* Packet 73 */
    0x65 };
    char peer0_28[] = { /* Packet 75 */
    0x6c };
    char peer0_29[] = { /* Packet 77 */
    0x7f };
    char peer0_30[] = { /* Packet 79 */
    0x4c };
    char peer0_31[] = { /* Packet 81 */
    0x30 };
    char peer0_32[] = { /* Packet 83 */
    0x4c };
    char peer0_33[] = { /* Packet 85 */
    0x0d };

    process_and_print(peer0_13, sizeof(peer0_13));
    process_and_print(peer0_14, sizeof(peer0_14));
    process_and_print(peer0_15, sizeof(peer0_15));
    process_and_print(peer0_16, sizeof(peer0_16));
    process_and_print(peer0_17, sizeof(peer0_17));
    process_and_print(peer0_18, sizeof(peer0_18));
    process_and_print(peer0_19, sizeof(peer0_19));
    process_and_print(peer0_20, sizeof(peer0_20));
    process_and_print(peer0_21, sizeof(peer0_21));
    process_and_print(peer0_22, sizeof(peer0_22));
    process_and_print(peer0_23, sizeof(peer0_23));
    process_and_print(peer0_24, sizeof(peer0_24));
    process_and_print(peer0_25, sizeof(peer0_25));
    process_and_print(peer0_26, sizeof(peer0_26));
    process_and_print(peer0_27, sizeof(peer0_27));
    process_and_print(peer0_28, sizeof(peer0_28));
    process_and_print(peer0_29, sizeof(peer0_29));
    process_and_print(peer0_30, sizeof(peer0_30));
    process_and_print(peer0_31, sizeof(peer0_31));
    process_and_print(peer0_32, sizeof(peer0_32));
    process_and_print(peer0_33, sizeof(peer0_33));
}