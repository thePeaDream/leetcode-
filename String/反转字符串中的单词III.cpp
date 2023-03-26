class Solution {
public:
    string reverseWords(string s) //双指针
    {
        //保证space指向空格或'\0'
        int space = 0;

        //指向当前单词的开始和结尾
        int curWordBegin = 0;
        int curWordEnd = 0;

        //遍历字符串时，curWordEnd开始一定在space - 1的位置
        while(space <= s.size())//s[s.size()] = '\0'
        {
            if(s[space] == ' '|| s[space] == '\0')
            {
                //反转当前单词
                curWordEnd = space - 1;
                while(curWordEnd > curWordBegin)
                {
                    swap(s[curWordBegin], s[curWordEnd]);
                    curWordBegin++;
                    curWordEnd--;
                }
                
                //更新下一个单词的头部
                curWordBegin = space+1;
            } 
            space++;
        }
        return s;

    }
};
