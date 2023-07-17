#include <bits/stdc++.h> 
struct Node {
    Node* arr[2];
    int word = 0;
    bool find(int idx) { return arr[idx] == NULL; }
    void set(int idx, Node* node) { arr[idx] = node; }
    Node* get(int idx) { return arr[idx]; }
};

int maximumXor(vector<int> A)
{
    int ans = 0;
    Node* root = new Node();
    for(auto it : A) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int idx = (it >> i) & 1;
            if(node -> find(idx)) node -> set(idx, new Node());
            node = node -> get(idx);
        }
    }
    for(auto it : A) {
        Node* node = root;
        int curr = 0;
        for(int i = 31; i >= 0; i--) {
            int idx = ((it >> i) & 1) ^ 1;
            
            if (!node -> find(idx)) {
              curr |= (1 << i);
              node = node->get(idx);
            } else {
                node = node -> get(!idx);
            }
        }
        ans = max(ans, curr);
    }
    return ans;
}
