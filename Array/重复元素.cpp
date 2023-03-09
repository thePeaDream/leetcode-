class Solution {
public:
    /*bool containsDuplicate(vector<int>& nums) //暴力N^2
    {
        //从前往后遍历数组，遍历到的数字与之后的所有数字比较
        //若相同return true
        //遍历完后没有相同的两个数return false
        for(int i = 0; i < nums.size();i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }*/

    bool containsDuplicate(vector<int>& nums) //排序后遍历O(NlogN)
    {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])//检测相邻元素是否有相同的情况
                return true;
        }
        return false;
    }
};
