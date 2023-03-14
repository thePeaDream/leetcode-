class Solution {
public:
    int firstUniqChar(string s) 
    {
        //用数组下标映射s中字符的出现次数
        int arr[256] = { 0 };
        for(char& x: s)
            arr[(int)x]++;
        
        //遍历字符串，若当前字符在数组的出现次数为1，返回
        for(int i = 0; i < s.size();i++)
        {
            if(arr[(int)s[i]] == 1)
                return i;
        }
        return -1;
    }
};
