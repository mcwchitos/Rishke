#include <stdio.h>
#include <malloc.h>
typedef struct node{
	int value;
	struct node* next;
} Node;

Node *head = NULL;


void insert_node(int n){
	Node *cur = head;
	if(head == NULL){
		head = malloc(sizeof(Node));
		head->value = n;
		head->next = NULL;
	}
	else{
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = malloc(sizeof(Node));
		cur->next->value = n;
		cur->next->next = NULL;
	}
}
void delete_node(){
	Node *cur = head;
	if(head == NULL){
		printf("Sorry, but no");
		printf("\n");
	}
	else{
		Node* prev_cur = NULL;
		while(cur->next != NULL){
			prev_cur = cur;
			cur = cur->next;
		}
		
		free(cur);
		if(prev_cur != NULL)
			prev_cur->next = NULL;
		else
		    head = NULL;
	}
}
void print_nodes(){
	Node *cur = head;
	while(cur!=NULL) {
		printf("%d", cur->value);
		printf(" ");
		cur = cur->next;
	}
	printf("\n");
}

int main(){
	delete_node();
	insert_node(7);
	insert_node(9);
	print_nodes();
	delete_node();
	print_nodes();
	delete_node();
	print_nodes();
	return 0;
}
