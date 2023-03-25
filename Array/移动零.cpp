class Solution {
public:
    void moveZeroes(vector<int>& nums)//双指针 
    {
        int slow = -1;
        int fast = 0;

        //slow指向的值以及之前的值都是非0
        //fast用于遍历
        for(fast = 0; fast < nums.size();fast++)
        {
            if(nums[fast] == 0) continue;//忽略
            if(nums[fast] != 0)
            {
                //更新slow,更新slow指向的值
                slow++;
                nums[slow] =nums[fast]; 
            }
        }

        //此时将slow后面的数全置0
        slow += 1;
        while(slow < nums.size())
        {
            nums[slow] = 0;
            slow++;
        }

    }
};
