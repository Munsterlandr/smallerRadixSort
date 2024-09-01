/*
Created: 2023-12-11
Title: Optimized Base 2 Radix Sort
*/
#include <stdio.h>
#include <stdlib.h>

// CONSTANTS
unsigned int ONE = 1; // lets me ensure it's unsigned

// INPUT //
/*gets positive number from user.*/
unsigned int getPosNum(char prompt[]) {
    int successfullyRead;
    unsigned int output;
    while (successfullyRead != 1) {
        printf("%s",prompt);
        successfullyRead = scanf("%d", &output);
        if ( successfullyRead != 1) {
            printf("Value not read successfully, please try again.\n");
        }
    }
    printf("Value read successfully as %d.\n", output);
    return output;
}

// PROCESS //

/**/
void assignRandVals(unsigned int array[], int length) {
    int i;
    for (i=0;i<length;i++) {
        array[i]=rand();
    }
    return;
}


void flipArraySection(unsigned int array[], int low, int high) {
    unsigned int hold;
    for (int l = low, h = high; l < h; l++, h--) {
        hold = array[l];
        array[l] = array[h];
        array[h] = hold;
    }
}

void sortByBit(unsigned int arrayIn[], int bit, int arrayLen) {
    unsigned int hold[arrayLen];
    int ifOne = 0;
    int ifZero = arrayLen - 1;
    for (int i = 0; i < arrayLen; i++) {
        if ((arrayIn[i] >> bit) & ONE == ONE) { // bit shift followed by conjuction checks value of a single bit
            hold[ifOne] = arrayIn[i];
            ifOne++;
        } else {
            hold[ifZero] = arrayIn[i];
            ifZero--;
        }
    }

    flipArraySection(hold, ifZero+1, arrayLen-1);

    for (int i = 0; i < arrayLen; i++) { // copy array values over
        arrayIn[i] = hold[i];
    }
}

int confirmSorted(unsigned int array[], int length) {
    int target = length - 1; // should hopefully result in faster machine code by making it not need to get length-1 each iteration
    for (int i = 0; i < target; i++) {
        if (array[i] < array[i+1]) {
            return 0;
        }
    }
    return 1;
}

// OUTPUT //

/*Prints int arrays*/
void printArray(unsigned int array[], int len) {;
    printf("[");
    if (len != 0) {
        printf("%d", array[0]);
        for (int i = 1; i < len; i++) {
            printf(", %d", array[i]);
        }
    }
    printf("]");
    return;
}

// MAIN
int main() {
    int length = getPosNum("How big should the array be? ");
    unsigned int nums[length]; 
    assignRandVals(nums,length);

    printf("Initial array: "); printArray(nums, length); printf("\n");

    int bits = sizeof(ONE)*8; // number of bits in an unsigned int, makes sure of good compat
    for (int i = 0;i<bits;i++) {
        sortByBit(nums, i, length);
        printf("after sort of bit %d: ", i); printArray(nums, length); printf("\n");
    }

    if (confirmSorted(nums, length) == 1) {
        printf("Sort Finished successfully!\n");
    } else {
        printf("Sort failed, mun plz debug\n");
    }

    return 0;
}