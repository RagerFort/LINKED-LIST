//ALDE, PATRICK P.
// A complete working C++ program to demonstrate deletion in singly linked list 
#include<iostream> 
using namespace std;

// A linked list node 
class Node 
{ 
    public:
        int data; 
        Node *next; 
}; 

/* Given a reference (pointer to pointer) to the head of a list and an int, inserts a new node on the front of the list. */
void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = NULL;
    new_node = new Node();
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 

/* Given a reference (pointer to pointer) to the head of a list and a key, deletes the first occurrence of key in linked list */
void deleteNode(Node **head_ref, int key) 
{ 
    // Store head node 
    Node* temp = *head_ref, *prev; 

    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 

    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 

    // If key was not present in linked list 
    if (temp == NULL) 
        return; 

    // Unlink the node from linked list 
    prev->next = temp->next; 
    free(temp);  // Free memory 
} 

// This function prints contents of linked list starting from  
// the given node 
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout << node->data << "->";
        node = node->next; 
    } 
    cout << "NULL" << endl;
} 

/* Driver program to test above functions*/
int main() 
{ 
    /* Start with the empty list */
    Node* head = NULL;
    head = new Node();
    head->data = 7;
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 

    cout << "Created Linked List: ";
    printList(head); 
    deleteNode(&head, 1); 
    cout << "Linked List after Deletion of Node with value of 1: ";
    printList(head); 
    system("pause");
    return 0; 
}
