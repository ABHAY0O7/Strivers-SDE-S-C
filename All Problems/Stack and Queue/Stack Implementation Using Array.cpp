// Stack class.
class Stack {
    
public:
    vector<int> v;
    int n;
    int idx;
    Stack(int capacity) {
        // Write your code here.
        n = capacity;
        idx = 0;
        v.resize(n);
    }

    void push(int num) {
        if(idx != n) v[idx++] = num;
    }

    int pop() {
        // Write your code here.
        if(idx == 0) return -1;
        return v[--idx];
    }
    
    int top() {
        // Write your code here.
        if(idx == 0) return -1;
        return v[idx-1];
    }
    
    int isEmpty() {
        // Write your code here.
        return idx == 0;
    }
    
    int isFull() {
        // Write your code here.
        return idx == n;
    }
    
};

