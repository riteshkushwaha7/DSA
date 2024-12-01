




class MyStack {
    queue<int> q;
public:
    MyStack() {
       
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    
    int pop() {
        if (q.empty()) return -1; 
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        if (q.empty()) return -1; 
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
