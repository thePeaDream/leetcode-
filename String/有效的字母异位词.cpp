class Solution {
public:
    bool isAnagram(string string1, string string2) 
    {
        //用string1的字符作为数组下标，映射string1的每个字符的出现次数
        int arr[256] = { 0 };

        for(char& x: string1)
            arr[(int)x]++;
        
        //string2遍历到的字符 被数组映射后>0,string2的该字符与string1的相同字符抵消
        //否则不互为字母异位词
        for(char& x: string2)
        {
            if(arr[(int)x] == 0)
                return false;
            arr[(int)x]--;
        }

        //保证string1中的字符没有需要抵消的
        for(int i = 0; i < 256;i++)
        {
            if(arr[i]!=0)
                return false;
        }
        return true;
    }
};
