// ENE212-0060/2021  MWAURA CYRUS
// ENE212-0067/2021  TRACY NAMAYI
// ENE212-0068/2021  TRACY WAWIRA
// ENE212-0081/2021  IAN NDIRANGU  
// ENE212-0086/2021  TONNY MAISHA 

// using caesar cipher(Assymetric encryption)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void caesarCipher(char* text, int key, int decrypt);

int main(void) {
    int key = 3;
    char text[101];
    int choice;

    // Ask the user for the text to encrypt or decrypt
    printf("Enter the text you want to encrypt or decrypt: ");
    fgets(text, sizeof(text), stdin);

    // Ask the user for the choice
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("The encrypted text is: ");
        caesarCipher(text, key, 0); // 0 indicates encryption
    } else if (choice == 2) {
        printf("The decrypted text is: ");
        caesarCipher(text, key, 1); // 1 indicates decryption
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

void caesarCipher(char* text, int key, int decrypt) {
    int i = 0;
    int shift = decrypt ? -key : key; // Determine the shift based on encryption or decryption
    int cipherValue;
    char cipher;

    while (text[i] != '\0' && strlen(text) - 1 > i) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            cipherValue = ((int)text[i] - 'a' + shift + 26) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            cipherValue = ((int)text[i] - 'A' + shift + 26) % 26 + 'A';
        } else {
            // Leave non-alphabetic characters unchanged
            cipherValue = text[i];
        }
        cipher = (char)(cipherValue);
        printf("%c", cipher);
        i++;
    }
    printf("\n");
}

