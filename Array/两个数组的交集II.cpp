class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) //数组映射
    {
        vector<int> re;
        //用一个数组记录nums1中每个数字的出现次数
        int arr[1001] = { 0 };
        for(int&x: nums1)
            arr[x]++;
        
        //遍历nums2,若遍历到的数字在arr中出现，添加到re中，并把该数字的出现次数-1
        for(int&x: nums2)
        {
            if(arr[x] > 0)
            {
                re.push_back(x);
                arr[x]--;
            }
        }
        return re;
    }
};
