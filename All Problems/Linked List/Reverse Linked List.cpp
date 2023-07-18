#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    #define Node LinkedListNode<int>
    
    Node* prev = NULL;
    while(head) {
        Node* next = head -> next;
        head -> next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
