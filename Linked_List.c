#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};
//Function to traverse the elements of linked list
void listTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            printf("%d", ptr->value);
            ptr = ptr->next;
        }
        else
        {
            printf("%d-> ", ptr->value);
            ptr = ptr->next;
        }
    }
    printf("\n");
}
//Function to input values and use them in linked list
//Inserting element at beging
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->value = data;

    ptr->next = head;
    return ptr;
}
//Inserting at end
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->value = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
//Inserting node at index m
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->value = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
//Function for deleting node with given key
void deleteByValue(struct Node** head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->value == key) {
        *head_ref = temp->next;
        free(temp); 
        return;
    }
    while (temp != NULL && temp->value!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
//Function for Removing Duplicates
struct Node *removeDuplicates(struct Node *head)
{
    struct Node *p1, *p2, *temp;
    p1 = head;
    while (p1 != NULL && p1->next != NULL)
    {
        p2 = p1;
        while (p2->next != NULL)
        {
            if (p1->value == p2->next->value)
            {
                temp = p2->next;
                p2->next = p2->next->next;
                free(temp);
            }
            else
                p2 = p2->next;
        }
        p1 = p1->next;
    }
}
//Function to find lenght of a linked list
int lenghtList(struct Node *head_ref){
    struct Node *tail = (struct Node *)malloc(sizeof(struct Node));
    tail= head_ref;
	int len=0;
	while(tail!=0)
	{
		tail=tail->next;
		len++;
	}
    return len;
}
//Function to find avarage
float avgList(struct Node *head_ref){
    struct Node *tail = (struct Node *)malloc(sizeof(struct Node));
    tail= head_ref;
	int len=0;
    float sum=0.0;
	while(tail!=0)
	{
		sum=sum+tail->value;
		tail=tail->next;
		len++;
	}
    	float avg= (sum/len);
        return avg;
}
//Function to display middle element
    int midList(struct Node *head_ref){
    struct Node *tail = (struct Node *)malloc(sizeof(struct Node));
    tail=head_ref;
    int len= lenghtList(head_ref);
	int i=1;
	while(i<(len+1)/2)
	{
		tail=tail->next;
		i++;
	}
    return tail->value;
}
//Function to find the maximum element of a linked list
int maxList(struct Node *ptr)
{
        int large=ptr->value;
        while(ptr!=NULL)
        {
                if(ptr->value >large)
                        large = ptr->value;
                ptr=ptr->next;
        }
        return large;
}
// Function to swap data of two nodes a and b
void swap(struct Node *a, struct Node *b)
{
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}
//Function for sorting a linked list
void sortList(struct Node *head_ref)
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;
    if (head_ref == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = head_ref;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->value > ptr1->next->value)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
  
//Function to Reverse a linked list
static void reverseList(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
//Main function
void main()
{
    int n, temp = 0, ins_value, m, y;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tail = (struct Node *)malloc(sizeof(struct Node));
    printf(" Enter the number of elements:\n ");
    scanf("%d", &n);
    printf("\n Enter the input elements:\n");
    printf("\n Enter index 0 element: ");
    scanf("%d", &temp);
    head->value = temp;
    head->next = NULL;
    for (int i = 1; i < n; i++)
    {
        printf("\n Enter index %d element: ", i);
        scanf("%d", &temp);
        insertAtEnd(head, temp);
    }
    printf("1. The Linked list after adding nodes with the values provided is:\n");
    listTraversal(head);
    printf("Next to add a node insert value x at index m(index should be between 1 to n):\n");
    printf(" x: \t");
    scanf("%d", &ins_value);
    printf("\n m: \t");
    scanf("%d", &m);
    insertAtIndex(head, ins_value, m-1);
    printf("2. The Linked list after Inserting a node to the list is:\n");
    listTraversal(head);
    printf("Enter the value you want to delete:\n");
    scanf("%d", &y);
    deleteByValue(&head, y);
    printf("3. The Linked list after deleting the node to the list is:\n");
    listTraversal(head);
    printf("4. The Linked List after Removing all duplicate value nodes from the Linked List:\n");
    removeDuplicates(head);
    listTraversal(head);
	printf("5.(a)Length of the Linked list : %d\n" , lenghtList(head));
	printf("5.(b)The Middle element of the Linked list is: %d\n", midList(head));
	printf("5.(c)The Avarage of the Linked list is : %.8f\n", avgList(head));
	printf("5.(d)The Maximum element of the Linked list is : %d\n", maxList(head));
    printf("6. The linked list after being sorted will be: \n ");
    sortList(head);
    listTraversal(head);
    printf("7. The linked list after being reversed will be: \n ");
    reverseList(&head);
    listTraversal(head);
}