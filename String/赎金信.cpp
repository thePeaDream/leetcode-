class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        //判断 ransomNote 能不能由 magazine 里面的字符构成

        //用数组映射magazine里的出现字符
        int arr[256] = { 0 };
        for(char& x: magazine)
            arr[(int)x]++;
        //字符作为下标，在数组中找到对应字符在magazine的出现次数
        
        //遍历ransomNote,若当前字符没在数组中出现return false
        //若出现 arr[(int)x]-- 
        for(char& x: ransomNote)
        {
            arr[(int)x]--;
            if(arr[(int)x] < 0)
                return false;
        }
        return true;
    }
};
