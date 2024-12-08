
#include <stdio.h>

int main() {
    int evenNumbers[11]; // Array to hold even numbers from 100 to 120
    int index = 0;

    // Fill the array with even numbers from 100 to 120
    for (int i = 100; i <= 120; i++) {
        if (i % 2 == 0) {
            evenNumbers[index] = i;
            index++;
        }
    }

    // Print the even numbers
    printf("Even numbers from 100 to 120 are:\n");
    for (int i = 0; i < index; i++) {
        printf("%d ", evenNumbers[i]);
    }

    return 0;
}
