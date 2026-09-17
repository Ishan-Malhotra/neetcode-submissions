class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n = asteroids.size();
        stack < int > myStack; 

    
        for(int i = 0; i < n; i++)
        {
            int aster = asteroids[i];
            bool destroyed = false;

                //if(same sign add to stack) //collision can only happen when top moves left and incoming moves right
                while(!myStack.empty() && myStack.top() > 0 && aster < 0)
                {
                
                
                    if(abs(myStack.top()) > abs(aster))
                    {
                        //incoming astroid destroyed
                        destroyed = true;
                        break;
                    }
                    else if(abs(myStack.top()) < abs(aster))
                    {
                        myStack.pop();
                        //destroyed stack asteroid
                        continue;
                    }
                    else
                    {
                        myStack.pop();
                        destroyed = true;
                        break;
                    }
                } 

                if(!destroyed)
                {
                myStack.push(aster);
                }
        }

        int t = myStack.size();
        vector<int> res(t);

        for(int i = t-1; i >= 0; i--)
        {
            res[i] = myStack.top();
            myStack.pop();
        }
        return res;
    }
};