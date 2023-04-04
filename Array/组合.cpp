//组合是指从给定的数集合中选择若干个数，
//组合中的数不能重复
//组合内数的顺序不重要

class Solution {
public:
    vector<vector<int>> combine(int n, int k)//递归回溯 返回[1,n]中所有可能的k个数组合 
    {
        vector<vector<int>> ret;
        
        //存放当前的一个组合
        vector<int> cur;

        combineChild(cur,1,n,k,ret);
        return ret;
    }

private:
    //[start,end]里选k个不重复的数，放入cur当前组合
    void combineChild(vector<int>& cur,int start, int end,int k, 
                      vector<vector<int>>& ret)
    {
        if(k == 0)//如果已经选够了k == 0 或者 cur.size() = 最开始的k 
        {
            //把该组合放入ret
            ret.push_back(v);
            return;
        }

        //在每个循环迭代中，要选择[start,end]的一个数加入组合或不加入组合
        //因为不能选相同的数
        //所以在递归中，下一个数字的范围应该[start+1,end]      
        for(int i = start;i <= end;i++)
        {
            //将当前数字加入当前组合
            v.push_back(i);

            //从下一个数字开始选取，并且可选数字-1
            combineChild(v,i+1,end,k-1,ret);

            //回溯到上一个状态，将当前数字从组合中移除
            v.pop_back();
        }
    }
};
