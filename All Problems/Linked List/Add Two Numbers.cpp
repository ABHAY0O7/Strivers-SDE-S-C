/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
#define ListNode Node

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    int carry = 0;
    Node* head = l1;
    Node* prev;
    while(l1 && l2) {
        int curr = carry;
        curr += l2 -> data;
        curr += l1 -> data;
        
        carry = (curr / 10);
        curr %= 10;

        l1 -> data = curr;
        prev = l1;
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    if(l2) {
        prev -> next = l2;
        while(carry != 0 && l2) {
            l2 -> data += carry;
            carry = l2 -> data / 10;
            prev = l2;
            l2 -> data %= 10;
            l2 = l2 -> next;
        }
        if(carry) {
            Node* node = new Node(carry);
            prev -> next = node;
        }
    } else {
        while(carry != 0 && l1) {
            l1 -> data += carry;
            carry = l1 -> data / 10;
            prev = l1;
            l1 -> data %= 10;
            l1 = l1 -> next;
        }
        if(carry) {
            Node* node = new Node(carry);
            prev -> next = node;
        }
    }
    
    return head;
}
// Node *addTwoNumbers(Node *num1, Node *num2)
// {
    
// }

