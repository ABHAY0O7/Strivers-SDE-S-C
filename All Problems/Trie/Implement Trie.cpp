/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class Node {

    Node* arr[26];
    bool word = 0;

    public:
    Node* get(int val) { return arr[val]; }
    void set(int val, Node* node) { arr[val] = node; }
    bool find(int val) { return arr[val] == NULL; }

    void setword() { word = 1; }
    bool getword() { return word; }
};

class Trie {

public:

    /** Initialize your data structure here. */
    Node* head;
    Trie() {
        head = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *curr = head;

        for(auto it : word) {
            int val = it - 'a';
            if(curr -> find(val)) curr -> set(val, new Node());
            curr = curr -> get(val);
        }
        curr -> setword();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = head;

        for(auto it : word) {
            int val = it - 'a';
            if(curr -> find(val)) return 0;
            curr = curr -> get(val);
        }
        return curr -> getword();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node* curr = head;

        for(auto it : word) {
            int val = it - 'a';
            if(curr -> find(val)) return 0;
            curr = curr -> get(val);
        }
        return 1;
    }
};
