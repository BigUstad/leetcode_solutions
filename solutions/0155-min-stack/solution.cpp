class MinStack {
public:
    MinStack() {
        // TODO: Think of something here.
    }
    
    void push(int val) {
        int min = val;
        if (!s.empty()) {
            auto p = s.top();
            min = std::min(val, p.second);
        }
        s.push({val, min});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }

private:
    std::stack<std::pair<int, int>> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
