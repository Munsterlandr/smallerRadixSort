/*
Created: 2023-12-11
Title: Optimized Base 2 Radix Sort
*/
#include <stdio.h>
#include <stdlib.h>

// CONSTANTS

// INPUT
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

// PROCESS

/**/
void assignRandVals(unsigned int array[], int length) {
    int i;
    for (i=0;i<length;i++) {
        array[i]=rand();
    }
    return;
}
// OUTPUT

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

    

    return 0;
}