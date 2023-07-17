class Stack {
	// Define the data members.

    public:
    queue<int> q;
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q.push(element);
    }

    int pop() {
        if(isEmpty()) return -1;
        // Implement the pop() function.
        int sa = q.size();
        for(int i = 0; i < sa - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        // Implement the top() function.
        if(isEmpty()) return -1;
        int ans = pop();
        push(ans);
        return ans;
    }
};
