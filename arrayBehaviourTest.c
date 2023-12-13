// This is more or less useless to the project as a whole, but it does tell me that i can modify arrays in functions.

#include <stdio.h>

int changeArray(int array[]) {
    array[0]=0;
    return 0;
}

int printArray(int array[]) {
    int i;
    printf("In array: ");
    for (i = 0; i < 5; i++) {
        printf("%d, ", array[i]);
    }
    printf("\b\b\n");
}

int main() {
    int array[5]={1,2,3,4,5};
    printArray(array);
    changeArray(array);
    printArray(array);
    return 0;
}