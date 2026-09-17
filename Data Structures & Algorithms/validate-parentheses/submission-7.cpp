class Solution {
public:
    bool isValid(string s) 
    {
        stack <char> mystack;
        int n = s.size();

        if(n == 1)
        return false;

        for(int i = 0; i < n; i++)
        {
            char ch = s[i];

            if(ch == '(' || ch == '[' || ch == '{')
            {
                mystack.push(ch);
            }

            else if(!mystack.empty() && ch == ')' && mystack.top() == '(')
            {
                mystack.pop();
                continue;
            }

            else if(!mystack.empty() && ch == ']' && mystack.top() == '[')
            {
                mystack.pop();
                continue;
            }

             else if(!mystack.empty() && ch == '}' && mystack.top() == '{')
            {
                mystack.pop();
                continue;
            }
            else
            return false;
        }

        if(mystack.empty())
        return true;
        else
        return false;
        
    }
};
