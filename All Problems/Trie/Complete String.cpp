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

string completeString(int n, vector<string> &a){
    Node* root = new Node();

    for(auto word : a) {
        Node* node = root;
        for(auto it : word) {
            int idx = it - 'a';
            if(node -> find(idx)) node -> set(idx, new Node());
            node = node -> get(idx);
        } 
        node -> setWord();
    }
    string ans;
    for(auto word : a) {
        Node* node = root;
        string s;
        for(auto it : word) {
            int idx = it - 'a';
            if(node -> find(idx)) break;
            node = node -> get(idx);
            if(node -> getWord()) break;
            s.push_back(idx+'a');
        }
        if(s.size() > ans.size()) swap(ans, s);
        else if(s.size() == ans.size() && ans > s) swap(ans, s);
    }
    return ans.size() ? ans : "None";
}
