#include <bits/stdc++.h> 
struct Node {
    Node* arr[26];
    int word = 0;
    bool find(int idx) { return arr[idx] == NULL; }
    void set(int idx, Node* node) { arr[idx] = node; }
    Node* get(int idx) { return arr[idx]; }
    int getWord() { return word == 0; }
    void setWord() { word = 1; }
};

int distinctSubstring(string &word) {
    
    int ans = 0;
    int n = word.size();
    Node* root = new Node();
    for(int i = 0; i < n; i++) {
        Node* node = root;
        for(int j = i; j < n; j++) {
            int idx = word[j] - 'a';

            if(node -> find(idx)) node -> set(idx, new Node());
            node = node -> get(idx);
            if(node -> getWord()) ans++;
            node -> setWord();
        }
    }
    return ans;
}

