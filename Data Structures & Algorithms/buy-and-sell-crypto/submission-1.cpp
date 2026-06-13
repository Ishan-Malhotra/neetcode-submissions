class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        //we have to return the max profit
        //we have to buy and we also have to sell

        int l = 0; //when we buy
        int r = 1; //when we sell

        int profit = 0;
        int maxprofit = 0;

        while(r < prices.size())
        {

        if(prices[l] > prices[r])
        {
            l = r;
        }
        else
        {
            profit = prices[r] - prices[l];
            maxprofit = max(maxprofit, profit);
        }
        r++;
        }

        return maxprofit;
    }
};
