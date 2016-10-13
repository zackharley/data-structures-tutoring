#include <stdio.h>
#include <stdlib.h>

int top = -1;
int stack[100];

int push(int n) {
	if(top == 99) {
		return 0; // failed
	}
	stack[++top] = n;
	return 1; //success
}

int pop(int *value) {
	if(top == -1) {
		return 0;
	}
	*value = stack[top--];
	return 1;
}

int tos(int **ptop) {
	if(top == -1) {
		return 0;
	}

	*ptop = &stack[top];
	return 1;
}

int main() {
	push(10);
	push(20);
	push(30);
	push(40);
	int *value = malloc(sizeof(int));

	pop(value);
	printf("%d\n", *value);
	pop(value);
	printf("%d\n", *value);
	pop(value);
	printf("%d\n", *value);
	pop(value);
	printf("%d\n", *value);


	return 1;
}