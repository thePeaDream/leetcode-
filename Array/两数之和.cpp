class Solution {
public:
    /*vector<int> twoSum(vector<int>& nums, int target) //暴力O(N)
    {
        vector<int> re;
        re.resize(2);

        //从头开始遍历数组
        //遍历到的数nums[pre] 与后面的所有数字分别相加
        for(int pre = 0; pre < nums.size()-1; pre++)
        {
            for(int post = pre + 1; post < nums.size();post++)
            {
                //符合条件则返回
                if(nums[pre] + nums[post] == target)
                {
                    re[0] = pre;
                    re[1] = post;
                    return re;
                }
            }
        }
        return re;
    }*/
};
