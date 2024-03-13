
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

bool is_prime(int number) {
    if (number < 2)
        return false;

    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0)
            return false;
    }

    return true;
}

int generate_prime(int min_value, int max_value) {
    int prime;
    do {
        prime = rand() % (max_value - min_value + 1) + min_value;
    } while (!is_prime(prime));
    return prime;
}

int mod_inverse(int e, int phi) {
    for (int d = 3; d < phi; d++) {
        if ((d * e) % phi == 1)
            return d;
    }
    printf("mod_inverse does not exist\n");
    exit(EXIT_FAILURE);
}

// Define GCD function
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    srand(time(NULL));

    int min_value = 1000, max_value = 5000;
    int p, q;

    p = generate_prime(min_value, max_value);
    q = generate_prime(min_value, max_value);
    while (p == q) {
        q = generate_prime(min_value, max_value);
    }

    int n = p * q;
    int phi_n = (p - 1) * (q - 1);

    int e;
    do {
        e = rand() % (phi_n - 2) + 2; // Random between 2 and phi_n-1
    } while (gcd(e, phi_n) != 1);

    int d = mod_inverse(e, phi_n);

    
    printf("n: %d\n", n);
    printf("phi of n: %d\n", phi_n);
    printf("p: %d\n", p);
    printf("q: %d\n", q);
    printf("Public key: %d\n", e);
    printf("Private key: %d\n", d);

    // Prompt user to enter message
    char message[100];
    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove trailing newline if present

    // Encrypt
    int ciphertext[strlen(message)];
    for (int i = 0; message[i] != '\0'; i++) {
        ciphertext[i] = (int)fmod(pow(message[i], e), n);
    }

    // Decrypt
    char decrypted_message[strlen(message) + 1];
    for (int i = 0; i < strlen(message); i++) {
        decrypted_message[i] = (char)fmod(pow(ciphertext[i], d), n);
    }
    decrypted_message[strlen(message)] = '\0';

    printf("Ciphertext: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%d ", ciphertext[i]);
    }
    printf("\n");

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}
