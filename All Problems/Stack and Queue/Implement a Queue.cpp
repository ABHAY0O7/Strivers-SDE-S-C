#include <bits/stdc++.h> 
class Queue {
public:
    vector<int> v;
    int fr, ba;
    int sa;
    Queue() {
        // Implement the Constructor
        v.resize(5005);
        fr = ba = sa = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return sa == 0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        v[ba++] = data;
        sa++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) return -1;
        int ans = v[fr];
        fr++;
        sa--;
        if(fr == ba) fr = ba = 0;
        return ans;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) return -1;
        return v[fr];
    }
};
