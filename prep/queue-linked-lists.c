#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* next;
} Node;

Node *front;
Node *end;
int count = 0;

void addToQueue(int n) {
	Node *new = (Node *)malloc(sizeof(Node));
	new->value = n;
	new->next = NULL;

	if(end != NULL) {
		end->next = new;
	}
	end = new;
	if(front == NULL) {
		front = new;
	}
	count++;
}

int removeFromQueue(int *value) {
	if(count == 0) {
		return 0;
	}
	Node *temp = front;
	*value = front->value;
	front = front->next;
	free(temp);
	count--;
	return 1;
}

int main() {
	int *a = malloc(sizeof(int));

	addToQueue(10);
	removeFromQueue(a);

	printf("%08x\n", a); // address
	printf("%d\n", *a); // value

	return 1;
}
