class Solution {
public:
    /*vector<int> sortedSquares(vector<int>& nums)//直接排序 
    {
        vector<int> ret;
        int i = 0;
        while(i < nums.size())
        {
            ret.push_back(nums[i]*nums[i]);
            i++;
        }

        //排序
        sort(ret.begin(), ret.end());
        return ret;
    }*/
    
    vector<int> sortedSquares(vector<int>& nums)//双指针+归并
    {
        vector<int> ret;

        int dividingLine;//假设正数和负数的分割点
        //[0, dividingLine-1]的平方都是单调递减，[dividingLine, nums.size()]的平方单调递增

        //找到第一个非负数
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= 0)
            {
                dividingLine = i;
                break;
            }
        }

        //归并，每次比较选出最大值
        int left = dividingLine - 1;
        int right = dividingLine;
        while(left>=0 && right < nums.size())
        {
            if(nums[left]*nums[left] > nums[right]*nums[right])
            {
                ret.push_back(nums[right]*nums[right]);
                right++;
            }
            else
            {
                ret.push_back(nums[left]*nums[left]);
                left--;
            }
        }

        if(left < 0)//负数平方已经全部有序放入目标数组
        {
            while(right < nums.size())
            {
                ret.push_back(nums[right]*nums[right]);
                right++;
            }
        }
        else//正数的平方已经全部放入目标数组
        {
            while(left >= 0)
            {
                ret.push_back(nums[left]*nums[left]);
                left--;
            }
        }
        return ret;
    }

};
