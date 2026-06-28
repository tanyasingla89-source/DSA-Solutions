class MinStack {
public:
stack<long long>s;
long long minval=INT_MAX;
    MinStack() { 
    }
    
    void push(int value) {
        if(s.empty()) {s.push(value); minval=value;}
        else
        {
            if(value<minval)
            {
                s.push((long long)2*value-minval);
                minval=value;
            }
            else
            {
                s.push(value);
            }
        }
    }
    
    void pop() {

        if(s.top()<minval)
        {
            minval=2*minval-s.top();
            s.pop();
        }
        else
        {
            s.pop();
        }
    }
    
    int top() {
        if(s.top()<minval)
        {
            return minval;
        }
        else
        {
            return s.top();
        }
    }
    
    int getMin() {
        return minval;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
