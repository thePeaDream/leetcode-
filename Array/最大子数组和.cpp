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
};
