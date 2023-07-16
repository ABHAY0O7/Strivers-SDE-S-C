#include <bits/stdc++.h> 

struct Node {
    Node* arr[26];
    int prefix = 0;
    int word = 0;

    bool find(int idx) { return arr[idx] == NULL; }
    void set(int idx, Node* node) { arr[idx] = node; }
    Node* get(int idx) { return arr[idx]; }

    void incWord() { word++; }
    void incPrefix() { prefix++; }
    void decWord() { word--; }
    void decPrefix() { prefix--; }

    int getWord() { return word; }
    int getPrefix() { return prefix; }
};

class Trie{

    public:

    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(auto it : word) {
            int idx = it - 'a';
            if(node -> find(idx)) node -> set(idx, new Node());
            node = node -> get(idx);
            node -> incPrefix();
        } 
        node -> incWord();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(auto it : word) {
            int idx = it - 'a';
            if(node -> find(idx)) return 0;
            node = node -> get(idx);
        } 
        int ans = node -> getWord();
        return ans;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(auto it : word) {
            int idx = it - 'a';
            if(node -> find(idx)) return 0;
            node = node -> get(idx);
        } 
        int ans = node -> getPrefix();
        return ans;
    }

    void erase(string &word){
        Node* node = root;
        for(auto it : word) {
            int idx = it - 'a';
            node = node -> get(idx);
            node -> decPrefix();
        } 
        node -> decWord();
    }
};

