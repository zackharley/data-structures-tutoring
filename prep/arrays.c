#include <stdio.h>
#include <stdlib.h>

int arrayOne[5] = {2, 4, 6, 8, 10};

int main() {
	int i;
	int j;
	int arrayTwo[4];
	int matrix[3][3];

	printf("%08x\n\n", arrayOne);

	// Print memory addresses of 
	for(i = 0; i < 5; i++) {
		// BE CAREFUL!! i is not the integer stored in the array! It is the index in the for loop!
		printf("Address of index %d in arrayOne: %08x\n", i, &arrayOne[i]);
	}

	printf("\n");

	for(i = 0; i < 4; i++) {
		printf("Address of index %d in arrayTwo: %08x\n", i, &arrayTwo[i]);
	}

	printf("\n");


	// Access values in array
	printf("%d\n", arrayOne[2]);
	printf("%d\n\n", *(arrayOne + 2));


	// Print memory addresses for multidimensional array
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("Address of matrix[%d][%d]: %08x\n", i , j, &matrix[i][j]);
		}
	}

	return 0;
}