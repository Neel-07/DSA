// C++ program to get intersection point of two linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
    int data;
    Node* next;
      Node(int x) {
        data = x;
          next = NULL;
    }
};

/* function to get the intersection point of two linked
lists head1 and head2 */
Node* getIntesectionNode(Node* head1, Node* head2)
{
    while (head2) {
        Node* temp = head1;
        while (temp) {
            // if both Nodes are same
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    // intersection is not present between the lists
    return NULL;
}

// Driver Code
int main()
{
    /*
        Create two linked lists

        1st 3->6->9->15->30
        2nd 10->15->30

        15 is the intersection point
    */

    Node* newNode;

    // Addition of new nodes
    Node* head1 = new Node(10);
    Node* head2 = new Node(3);
  
    head2->next = new Node(6);
    head2->next->next = new Node(9);

    newNode = new Node(15);
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node(30);
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    Node* intersectionPoint
        = getIntesectionNode(head1, head2);

    if (!intersectionPoint)
        cout << " No Intersection Point \n";
    else
        cout << "Intersection Point: "
             << intersectionPoint->data << endl;
}

// This code is contributed by Tapesh(tapeshdua420)
