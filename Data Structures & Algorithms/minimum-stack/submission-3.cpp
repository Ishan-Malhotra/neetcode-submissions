class MinStack {
public:

    stack <int> myStack;
    stack<int> miniStack;
    int mini = INT_MAX;

    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        myStack.push(val);
        
        if(miniStack.empty() || val <= miniStack.top())
        {
            miniStack.push(val);
        }
    }
    
    void pop() 
    {
        if(!myStack.empty())
        {
            if(miniStack.top() == myStack.top())
            miniStack.pop();
        }
        myStack.pop();
    }
    
    int top() 
    {
        return myStack.top();
    }
    
    int getMin() 
    {
       return miniStack.top();;
    }
};
