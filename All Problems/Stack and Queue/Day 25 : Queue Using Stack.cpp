class Queue {
    // Define the data members(if any) here.
    stack<int> *st1, *st2;
    public:
    Queue() {
        st1 = new stack<int>();
        st2 = new stack<int>();
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        while(!st1 -> empty()) {
            st2 -> push(st1 -> top());
            st1 -> pop();
        }
        st2 -> push(val);
        while(!st2 -> empty()) {
            st1 -> push(st2 -> top());
            st2 -> pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(isEmpty()) return -1;
        int ans = st1 -> top();
        st1 -> pop();
        return ans;
    }

    int peek() {
        if(isEmpty()) return -1;
        // Implement the peek() function here.
        return st1 -> top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return st1 -> empty();
    }
};
