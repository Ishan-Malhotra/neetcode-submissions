class MinStack {
public:

    stack <int> myStack;

    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        myStack.push(val);
    }
    
    void pop() 
    {
        if(!myStack.empty())
        myStack.pop();
    }
    
    int top() 
    {
        
        return myStack.top();
    }
    
    int getMin() 
    {
       stack <int> temp1 = myStack;
       int mini = INT_MAX;
       
       while(!myStack.empty())
       {
        mini = min(mini, myStack.top());
        myStack.pop();
       }
       myStack = temp1;
       return mini;

    }
};
