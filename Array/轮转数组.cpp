class Solution {
public:
    void rotate(vector<int>& nums, int k) //队列
    {
        //把有序序列从尾部开始入队列，
        queue<int> q;
        int i = nums.size()-1;
        while(i >= 0)
        {
            q.push(nums[i]);
            i--;
        }
        //队头 6 5 4 3 2 1 0 队尾

        k %= nums.size();
        
        //每次向右轮转一次，则出队列，并把刚刚出的元素重新入队列
        while(k > 0)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
            k--;
        }

        //此时队尾到队头的序列就是要形成的目标序列
        i = nums.size()-1;
        while(!q.empty())
        {
            nums[i] = q.front();
            i--;
            q.pop();
        }
    }
};
