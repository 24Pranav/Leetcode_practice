class MyStack {
public:
    deque<int> q;
    int x=0;
    MyStack() {
        
    }
    
    void push(int y) {
        q.push_back(y);
        x++;
    }
    
    int pop() {
        x--;
        int y=q.back();
        q.pop_back();
        return y;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return x==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */