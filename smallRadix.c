/*
Created: 2023-12-11
Title: Optimized Base 2 Radix Sort
*/
#include <stdio.h>

// INPUT
unsigned short int getPosNum(char prompt[]) {
    int successfullyRead;
    unsigned int output;
    while (successfullyRead != 1) {
        printf(prompt);
        if (scanf("%d", &output) != 1) {
            printf("Value not read successfully, please try again.");
        }
    }
    printf("Value read successfully as %d.", output);
    return output;
}

// PROCESS


// OUTPUT


// MAIN
int main() {
    unsigned short int arrayLen = getPosNum("How big should the array be? "); // get input array size from user
    unsigned short int maxNum = getPosNum("What's the highest unsigned 16 bit number you'll allow? ");

    unsigned short int nums[arrayLen];
    

    return 0;
}