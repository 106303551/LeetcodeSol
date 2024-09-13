class MyStack {
public:
    queue<int> queue1;
    MyStack() {
        
    }
    
    void push(int x) {
        int count = 0;
        queue1.push(x);
        while(count<queue1.size()-1){
            queue1.push(queue1.front());
            queue1.pop();
            count++;
        }
    }
    
    int pop() {
        int res = queue1.front();
        queue1.pop();
        return res;
    }
    
    int top() {
        return queue1.front();
    }
    
    bool empty() {
        return queue1.empty();
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