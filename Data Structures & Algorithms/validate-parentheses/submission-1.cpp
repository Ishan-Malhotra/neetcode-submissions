class Solution {
public:
    bool isValid(string s) 
    {
        stack <char> myStack;

        for(const auto &ch : s)
        {
            if((ch == '(') || (ch == '{') || (ch == '['))
            {
                myStack.push(ch);
            }

            else if (ch == ')')
            {
                if((myStack.empty()) || (myStack.top() != '('))
                return false;

                myStack.pop();
            }

            else if (ch == '}')
            {
                if((myStack.empty()) || (myStack.top() != '{'))
                return false;

                myStack.pop();
            }

            else if (ch == ']')
            {
                if((myStack.empty()) || (myStack.top() != '['))
                return false;

                myStack.pop();
            }
        }

        if(myStack.empty())
        return true;
        else
        return false;


    }
};
