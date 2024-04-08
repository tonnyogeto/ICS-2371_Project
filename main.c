// using caesar cipher(Assymetric encryption)

#include <stdio.h>
#include <stdlib.h>

int main(void) {
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
        // Send encrypted text
    } else if (choice == 2) {
        printf("The decrypted text is: ");
        // Send decrypted text
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}


