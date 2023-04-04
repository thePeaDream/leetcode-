class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ret;

        //存放当前排列的数字
        vector<int> curPer;

        //标记nums中的数字是否被加入排列中
        vector<bool> used(nums.size(),false);

        permuteChild(ret,nums,used, curPer);
        return ret;
    }

private:
    void permuteChild(vector<vector<int>>& ret,vector<int>& nums,
                 vector<bool>& used,vector<int>& curPer)
    {
        //如果全部数字被加入到当前排列
        if(curPer.size() == nums.size())
        {
            ret.push_back(curPer);
            return;
        }

        for(int i = 0; i < nums.size();i++)
        {
            if(!used[i])//如果当前数字没有被加入到排列中
            {
                //放进当前排列并标识已经使用
                curPer.push_back(nums[i]);
                used[i] = true;

                //剩下数字进行全排列
                permuteChild(ret,nums,used,curPer);
                
                //回溯
                curPer.pop_back();
                used[i] = false;
            }
        }      
    }
};
