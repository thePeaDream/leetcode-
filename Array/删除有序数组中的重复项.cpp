class Solution {
public:
    int removeDuplicates(vector<int>& nums)//双指针遍历 
    {
        int pre = 0;
        int post = 1;
        
        //[0,pre]区间代表无重复项的值
        //post指向的值为待考察的元素
        while(post < nums.size())
        {
            if(nums[pre] == nums[post])
                post++;
            else//新的值要加入到[0,pre]区间
            {
                pre++;
                nums[pre] = nums[post];
                post++;
            }
        }
        return pre+1;
    }
};
