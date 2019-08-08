class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() : totalEle(0){
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        totalEle++;
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if( stack1.empty() && stack2.empty())
        {
            throw underflow_error("Queue Empty.");
        }
        else if (stack2.empty() && !stack1.empty())
        {
            while ( !stack1.empty())
            {
                int popped = stack1.top();
                stack1.pop();
                stack2.push(popped);
            }
            totalEle--;
            if (stack2.empty())
            {
                throw range_error("Unable to extract for pop.");
            }
            int lRet = stack2.top();
            stack2.pop();
            return lRet;
        }
        else if (!stack2.empty())
        {
            totalEle--;
            int lRet = stack2.top();
            stack2.pop();
            return lRet;
        }
        throw logic_error("Some condition not handled.");
    }
    
    /** Get the front element. */
    int peek() {
        if (stack1.empty() && stack2.empty())
        {
            throw underflow_error("Queue Emtpy.");
        }
        else if ( !stack2.empty())
        {
            return stack2.top();
        }
        else if ( stack2.empty() )
        {
            if (stack1.empty())
                throw underflow_error("Queue EMpty");
            while ( !stack1.empty() )
            {
                int popped = stack1.top();
                stack1.pop();
                stack2.push(popped);
            }
            return stack2.top();
        }
        throw logic_error("Some condition not handled");
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return ( stack1.empty() && stack2.empty());
    }
 private:
    std::stack<int> stack1;
    std::stack<int> stack2;
    int totalEle;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
