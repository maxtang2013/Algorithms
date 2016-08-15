#include "../../MergeSortedLinkedList.cpp"

Node list1[10];
Node list2[15];

void PrintList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void Init()
{
    int i;
    int len = sizeof(list1) / sizeof(Node);
    for (i = 0 ; i < len; ++i)
    {
        
        if (i < len - 1)
            list1[i].next = &list1[i + 1];
        
        list1[i].data = i;
    }
    
    len = sizeof(list2) / sizeof(Node);
    for (i = 0; i < len; ++i)
    {
        if (i < len - 1)
            list2[i].next = &list2[i + 1];
        
        list2[i].data = i;
    }
    
}

int main()
{
    Init();
    PrintList(list1);
    PrintList(list2);
    
    Node* head = Merge(list1, list2);
    PrintList(head);
    return 0;
}
