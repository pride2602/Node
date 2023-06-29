#include "bits-stdc++.h"
#include <mutex>

struct Node {
    int data;
    Node* next;
    std::mutex* node_mutex;
};
class FineGrainedQueue
{
    Node* head;
    std::mutex* queue_mutex;
};

// function to create and return a node
Node* getNode(int data)
{
    // allocating space
    Node* newNode = (Node*)malloc(sizeof(Node));

    // inserting the required data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert node at the middle
// of the linked list
void FineGrainedQueue(Node** head, int x)
{
    // if list is empty
    if (*head == NULL)
        *head = getNode(x);

    else {

        // get a new node
        Node* newNode = getNode(x);

        Node* ptr = *head;
        int len = 0;

        // calculate length of the linked list
        //, i.e, the number of nodes
        while (ptr != NULL) {
            len++;
            ptr = ptr->next;
        }

        // 'count' the number of nodes after which
        //  the new node is to be inserted
        int count = ((len % 2) == 0) ? (len / 2) :
            (len + 1) / 2;
        ptr = *head;

        // 'ptr' points to the node after which 
        // the new node is to be inserted
        while (count-- > 1)
            ptr = ptr->next;

        // insert the 'newNode' and adjust the
        // required links
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

// function to display the linked list
void display(Node* head)
{
    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    // Creating the list 1->2->4->5
    Node* head = NULL;
    head = getNode(1);
    head->next = getNode(2);
    head->next->next = getNode(4);
    head->next->next->next = getNode(5);

    std::cout << "Linked list before insertion: ";
    display(head);

    int x = 3;

    FineGrainedQueue(&head, x);


    std::cout << "\nLinked list after insertion: ";
    
    display(head);

    return 0;
}