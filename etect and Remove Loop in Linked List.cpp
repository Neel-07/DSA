#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// A utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to detect and remove loop
// in a linked list 
void hashAndRemove(Node* head)
{
    // hash set to hash addresses of the linked list nodes
    unordered_set<Node*> node_set;
    // pointer to prev node
    Node* prev = NULL;
    while (head != NULL) {
        // if node not present in the map, insert it in the
        // map
        if (node_set.find(head) == node_set.end()) {
            node_set.insert(head);
            prev = head;
            head = head->next;
        }
        // if present, it is a cycle, make the last node's
        // next pointer NULL
        else {
            prev->next = NULL;
            break;
        }
    }
}
/* Driver program to test above function*/
int main()
{
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    // printList(head);
    hashAndRemove(head);

    printf("Linked List after removing loop \n");
    printList(head);

    return 0;
}
