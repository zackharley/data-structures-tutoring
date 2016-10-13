typedef struct Node {
	int value;
	struct Node* next;
} Node;

Node *head = NULL;
int size = 0;

void push(int n) {
	Node *new = (Node *)malloc(sizeof(Node));
	new->value = n;
	new->next = head;
	head = new;
	size++;
}

int pop() {
	Node *p = head;
	int result = p->value;
	head = p->next;
	free(p);
	size--;
	return result;
}

int *tos() {
	return &(head->value);
}

int main() {

}