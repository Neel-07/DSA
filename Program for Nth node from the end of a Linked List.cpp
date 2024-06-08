// C program to find N'th node from end
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Function to get the nth node from the last of a linked
 * list*/
void printNthFromLast(Node* head, int N)
{
    int len = 0, i;
    Node* temp = head;

    // Count the number of nodes in Linked List
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }

    // Check if value of N is not
    // more than length of the linked list
    if (len < N)
        return;
    temp = head;

    // Get the (len-N+1)th node from the beginning
    for (i = 1; i < len - N + 1; i++)
        temp = temp->next;
    printf("%d", temp->data);
    return;
}

void push(struct Node** head_ref, int new_data)
{
    /* Allocate node */
    Node* new_node = (Node*)malloc(sizeof(Node));

    /* Put in the data */
    new_node->data = new_data;

    /* link the old list of the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

// Driver's Code
int main()
{

    /* Start with the empty list */
    struct Node* head = NULL;

    // create linked 35->15->4->20
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
  
      // Function call
    printNthFromLast(head, 4);
    return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
