#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct Head {
	Node *next;
	int size;
} Head;

int main() {

	Head *head = (Head *) malloc(sizeof(Head));
	head->next = NULL;
	head->size = 0;

	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->value = 5;
	newNode->next = NULL;

	head->next = newNode;
	head->size += 1;

	Node *newNode2 = (Node *) malloc(sizeof(Node));
	newNode2->value = 6;
	newNode2->next = NULL;

	head->next = newNode2;
	newNode2->next = newNode;
	head->size += 1;

	printf("%d\n", head->next->value);
	printf("%d\n", head->next->next->value);
	
	return 0;
}