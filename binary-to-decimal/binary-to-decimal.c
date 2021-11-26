#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABSURDLY_LONG_NUMBER_OF_BITS 1000
#define ULONG_BIT_LENGTH sizeof(unsigned long) * 8

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    unsigned long decimal = 0;
    char *binary = malloc(sizeof(char) * ABSURDLY_LONG_NUMBER_OF_BITS);
    
    printf("Type your binary number: ");
    scanf("%s", binary);
    
    int size_of_input = strlen(binary);
    int most_significant_bit = min(ULONG_BIT_LENGTH, size_of_input);
    for (int i = 0; i < most_significant_bit; i++) {
        decimal = decimal | ((binary[size_of_input - 1 - i] & 1) << i);
    }

    printf("In decimal: %lu", decimal);
    return 0;
}
