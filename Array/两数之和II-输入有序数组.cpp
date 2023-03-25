class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)//双指针 
    {
        //头尾指针
        int begin = 0;
        int end = numbers.size() - 1;
        vector<int> ret;
        while(begin < end)
        {
            if(numbers[begin] + numbers[end] > target)
            {
                //选择较小的数
                end--;
            }
            else if(numbers[begin] + numbers[end] < target)
                begin++;
            else
            {
                //题目要求下标从1开始
                ret.push_back(begin+1);
                ret.push_back(end+1);
                break;
            }    
        }
        return ret;
    }
};
