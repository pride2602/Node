struct Node {
    int data;
    Node* next;
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
void insertAtMid(Node** head_ref, int x)
{
    // if list is empty
    if (*head_ref == NULL)
        *head_ref = getNode(x);
    else {

        // get a new node
        Node* newNode = getNode(x);

        Node* ptr = *head_ref;
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
        ptr = *head_ref;

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
        cout << head->data << " ";
        head = head->next;
    }
}