class Solution {
public:
    /*int maxSubArray(vector<int>& nums)//暴力 
    {
        //假设最大和就是第一个数
        int max = nums[0];

        //以nums[i]开始的所有连续子数组的和
        //与max做比较

        for(int i = 0; i < nums.size(); i++)
        {
            int sum = 0;

            //sum 记录 以nums[i]开始的所有连续子数组的和
            for(int j = i; j < nums.size();j++)
            {
                sum += nums[j];

                //每记录一次都要和max比较
                if(sum > max)
                    max = sum;
            }
        }
        return max;
    }*/
    int Max(int a, int b)
    {
        return a > b? a: b;
    }

    int maxSubArray(vector<int>& nums)//动态规划
    {
        //把大问题拆分为多个子问题
        //以nums[0]结尾的最大连续子数组和：放到dp[0] = nums[0]（初始值）
        //以nums[1]结尾的最大连续子数组和：放到dp[1]
        //…………
        //假设全是正数，dp[cur] = dp[cur-1]+nums[cur]
        //存在负数，若dp[i-1] < 0,  dp[cur] = nums[cur].
        //所以 dp[cur] = Max(dp[cur-1]+nums[cur], nums[cur]);
        int ret = nums[0];

        vector<int> dp;
        dp.resize(nums.size());
        dp[0] = nums[0];

        for(int cur = 1; cur < nums.size();cur++)
        {
            //看dp[cur-1]是否是负数
            dp[cur] = Max(dp[cur-1]+nums[cur],nums[cur]);

            //在填dp数组的同时选最大值
            if(dp[cur] > ret)
                ret = dp[cur];
        }

        return ret;

    }
};
