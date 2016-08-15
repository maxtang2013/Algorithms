#include <iostream>

class Node
{
public:
    int data;
    Node *next;
};

Node*  Merge(Node *head1, Node *head2)
{
    Node *head = NULL, *curr = NULL, *next = NULL;
    
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            next = head1;
            head1 = head1->next;
        }
        else
        {
            next = head2;
            head2 = head2->next;
        }
        
        if (head == NULL)
        {
            head = curr = next;
        }
        else
        {
            curr->next = next;
            curr = next;
        }
    }
    
    if (head1 != NULL)
    {
        curr->next = head1;
    }
    
    if (head2 != NULL)
    {
        curr->next = head2;
    }
    
    return head;
}
