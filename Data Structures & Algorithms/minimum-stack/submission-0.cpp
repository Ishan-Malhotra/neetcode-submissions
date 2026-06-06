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
        myStack.pop();
    }
    
    int top() 
    {
        return myStack.top();
    }
    
    int getMin() 
    {
        stack <int> temp;
        int mini = myStack.top();

        while(!myStack.empty())
        {
            mini = min(mini, myStack.top());
            temp.push(myStack.top());
            myStack.pop();
        }

        //now new stack is reverse of the old stack and min has the least value

        while(!temp.empty())
        {
            myStack.push(temp.top());
            temp.pop();
        }

        return mini;


    }
};
