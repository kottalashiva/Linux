#include "double_linked_list.h"
#include<stdio.h>
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

