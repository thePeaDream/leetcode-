class Solution {
public:
    int maxProfit(vector<int>& prices) //暴力
    {
        //假设最大利润为0
        int maxP = 0;

        //把所有买入卖出的情况列出来
        for(int buy = 0; buy < prices.size()-1;buy++)
        {
            for(int sale = buy+1; sale < prices.size();sale++)
            {
                //若利润更高，则修改maxP
                if(prices[sale]-prices[buy] > maxP)
                    maxP = prices[sale]-prices[buy];
            }
        }
        return maxP;
    }
};
