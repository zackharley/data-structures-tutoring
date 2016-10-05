#include <stdio.h>
#include <stdlib.h>

struct samples {
	struct samples *next;
	int value;
};

int main() {
	struct samples *head = NULL;
	struct samples *new = NULL;
	struct samples *end = NULL;
	struct samples *currentNode = NULL;
	struct samples *nodeToDelete = NULL;

	// Add first node to empty list
	new = (struct samples*) malloc(sizeof(struct samples));
	new->next = NULL;
	new->value = 42;

	if(head == NULL) {
		head = new;
	}

	printf("The value of head is: %d\n", head->value);
	printf("The value of head is: %d\n\n", (*head).value);


	// Add new node to head
	new = (struct samples*) malloc(sizeof(struct samples));
	new->next = NULL;
	new->value = 24;

	if(head->next == NULL) {
		head->next = new;
	}

	printf("The value of head is: %d\n", head->value);
	printf("The value of the next node after head is: %d\n\n", head->next->value);


	// Add to the end of linked list using while loop.
	new = (struct samples*) malloc(sizeof(struct samples));
	new->next = NULL;
	new->value = 1;

	end = head;

	while((end->next) != NULL) {
		end = end->next;
	}

	printf("The memory address of the next node after head is: %d\n", head->next);
	printf("The memory address of the final node in the list is: %d\n", end);
	printf("The memory address that the last node in the list points to is: %d\n", end->next);

	end->next = new;

	printf("The memory address that the last node in the list points to is: %d\n", end->next);

	end = end->next;

	printf("The memory address of the final node in the list is: %d\n", end);
	printf("The memory address that the last node in the list points to is: %d\n\n", end->next);


	//Print out current values in linked list
	printf("The values in the list are:\n");
	printf("%d\n", head->value);
	printf("%d\n", head->next->value);
	printf("%d\n\n", head->next->next->value);
	// printf("%d\n\n", head->next->next->next->value); // Segmentation fault due to invalid memory location


	// Add new node to beginning of linked list
	new = (struct samples*) malloc(sizeof(struct samples));
	new->next = NULL;
	new->value = 4;

	new->next = head;
	head = new;


	//Print out current values in linked list
	printf("The values in the list are:\n");
	printf("%d\n", head->value);
	printf("%d\n", head->next->value);
	printf("%d\n", head->next->next->value);
	printf("%d\n\n", head->next->next->next->value);


	// Add a node to somewhere in the middle of a list
	// We must first determine where we want to place the node in the list
	// We'll place it after 42 in the list
	new = (struct samples*) malloc(sizeof(struct samples));
	new->next = NULL;
	new->value = 18;

	currentNode = head;
	while(currentNode->value != 42) {
		currentNode = currentNode->next;
	}

	new->next = currentNode->next;
	currentNode->next = new;

	// Print out list
	currentNode = head;

	printf("The values in the list are:\n");
	printf("%d\n", currentNode->value);

	while(currentNode->next != NULL) {
		currentNode = currentNode->next;
		printf("%d\n", currentNode->value);
	}

	printf("\n");


	// Delete a node somewhere in the middle
	// We must first determine where in the list the node we want to delete is
	// We'll delete the node with value 24
	currentNode = head;

	while(currentNode->next->value != 24) {
		currentNode = currentNode->next;
	}

	nodeToDelete = currentNode->next;
	currentNode->next = nodeToDelete->next;
	free(nodeToDelete);


	// Print out list
	currentNode = head;

	printf("The values in the list are:\n");
	printf("%d\n", currentNode->value);

	while(currentNode->next != NULL) {
		currentNode = currentNode->next;
		printf("%d\n", currentNode->value);
	}

	printf("\n");
	

	return 0;
}