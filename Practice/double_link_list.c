#include "double_linked_list.h"
#include <stdio.h>

/*
int main()
{
	int n;
	int index;
	while(1)
	{
		printf("Enter\n");
		printf("1 to add at the start\n");
		printf("2 to add the at end\n");
		printf("3 to add specific index\n");
		printf("4 to display the data\n");
		printf("5 to delete the data from dll\n");
		printf("6 to delete the complete list\n");
		printf("7 to check if the data is empty\n");
		printf("99 to exit the loop\n");
		scanf("%d", &n);
		switch(n)
		{
			case(1):

				push_at_start();
				break;

			case(2):

				push_at_end();
				break;
			case(3):
				printf("enter the index number");
				scanf("%d", &index);
				push_at_index(index);
				break;
			case(4):
				display_data();
				break;
			case(5):
				delete_data_from_dll();
				break;
			case(6):
				delete_complete_list();
			case(7):
				is_empty();
				break;
			case(99):
				exit(1);
			default:
				printf("Wrong number\n");
				break;
		}
	}
}
*/

void push_at_start(){
	int data;
	printf("Enter the data to insert\n");
	scanf("%d", &data);
	struct Node* new = (struct Node *)malloc(sizeof(struct Node));
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	if(head == NULL)
	{
		head = new;
		// new->prev = head;
	}
	else{
		new->next = head;
		head->prev = new;
		head = new;
	}
}

struct Node* create(void)
{
	int data;
	printf("Enter the data to insert\n");
	scanf("%d", &data);
	struct Node* new = (struct Node *)malloc(sizeof(struct Node));
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

void push_at_end(){
	int data;
	struct Node *temp1;
	printf("Enter the data to insert\n");
	scanf("%d", &data);
	struct Node* new = (struct Node *)malloc(sizeof(struct Node));	
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	//traverse to the last element
	temp1 = head;

	while(temp1->next != NULL)
	{
		printf("data is %d\n", temp1->data);
		temp1 = temp1 -> next;
	}
	temp1->next = new;
	new->prev = temp1;
}

void push_at_index(int index){
	int iter = 1;
	int data;
	struct Node *temp1;
	printf("Enter the data to insert\n");
	scanf("%d", &data);
	struct Node* new = (struct Node *)malloc(sizeof(struct Node));
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	temp1 = head;
	while(temp1->next != NULL)
	{
		if(iter < index)
		{
			temp1 = temp1->next;
		}
		else
		{
			new->next = temp1->next;
			new->prev = temp1;
			temp1->next->prev = new;
			temp1->next = new;
			break;
		}
		iter++;
	}


}

void display_data(){
	struct Node *temp1;
	temp1 = head;

	while(temp1->next != NULL)
	{
		printf("data is %d\n", temp1->data);
		temp1 = temp1 -> next;
	}
	printf(" data is %d\n", temp1->data);
}

void is_empty(void)
{
	if(head == NULL)
		printf("Double linked list is empty\n");
	else
	{
		printf("Some data exist in the Double linked list\n");
		display_data();
	}
}

void delete_data_from_dll(void)
{
	struct Node *temp;
	int data;
	printf("Enter the data to delete\n");
	scanf("%d", &data);
	temp =  head;
	while(temp->next != NULL)
	{
		if(temp->data == data)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			break;
		}
		temp = temp->next;

	}
}

void delete_complete_list(void)
{
	struct Node *temp;
  	while(head != NULL)
  	{
    	temp = head;
    	head = head->next;
    	free(temp);
    }
}
