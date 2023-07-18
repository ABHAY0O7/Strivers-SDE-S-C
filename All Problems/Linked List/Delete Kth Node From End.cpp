/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int k)
{
    Node *slow = new Node();
    slow -> next = head;
    Node *ret = slow;
    while(k--) head = head -> next;
    while(head) {
        head = head -> next;
        slow = slow -> next;
    }
    slow -> next = slow -> next -> next;
    return ret -> next;
}

