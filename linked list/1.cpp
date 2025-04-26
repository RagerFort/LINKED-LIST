//ALDE, PATRICK P.
#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node *next;
};

int main()
{
// Creating three nodes
Node* head = NULL;
Node* second = NULL;
Node* third = NULL;
// Allocate 3 nodes in the head
head = new Node();
second = new Node();
third = new Node();
// Assign data and link nodes
head->data = 1; 
head->next = second; 
// Link first node with second
second->data = 2;
second->next = third;
// Link second node with the third
third->data = 3; 
third->next = NULL;

return 0;
}