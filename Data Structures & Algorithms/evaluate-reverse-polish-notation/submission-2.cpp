class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack <int> myStack;
         int ans; 

        for(const auto & token : tokens)
        {

            if(token == "+") 
            {
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();

                ans = b + a;
                myStack.push(ans);
            }

            else if (token == "-")
            {
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();

                ans = b - a;
                myStack.push(ans);

            }

            else if (token == "*")
            {
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();

                ans = b * a;
                myStack.push(ans);

            }

            else if (token == "*")
            {
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();

                ans = b * a;
                myStack.push(ans);

            }

            else if (token == "/")
            {
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();

                ans = b / a;
                myStack.push(ans);

            }

            else
            {
                myStack.push(stoi(token));
            }

        }

        return myStack.top();
        
    }
};
