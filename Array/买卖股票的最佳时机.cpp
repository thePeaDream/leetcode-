class Solution {
public:
   /* int maxProfit(vector<int>& prices) //暴力
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
    }*/
    int max(int a, int b)
    {
        return a > b? a : b;
    
    }
    int maxProfit(vector<int>& prices)//动态规划
    {
        //子问题：在第i天卖出能获得的最大利润

        //遍历同时记录历史上买入的最小值
        int historyBuyMin = prices[0];
        //prices[i] 减去 历史上买入的最小值 —— 得到这一天卖出能获得的最大利润
        int maxPf = 0;
        for(int todaySale = 1; todaySale < prices.size();todaySale++)
        {
            //第todaySale天卖出能获得的最大利润
            maxPf = max(prices[todaySale]-historyBuyMin, maxPf);
            //更新历史上买入的最小值
            if(historyBuyMin > prices[todaySale])
                historyBuyMin = prices[todaySale];
        }
        return maxPf;
    }
};
