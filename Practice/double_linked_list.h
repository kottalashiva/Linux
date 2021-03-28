 struct Node
 {
 	int data;
 	struct Node* prev;
 	struct Node* next;
 }*head, *temp;

void push_at_start();

void push_at_index(int index);

void push_at_end(void);

void is_empty(void);

void delete_data_from_dll(void);

void delete_complete_list(void);
void display_data(void);
