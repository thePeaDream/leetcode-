class Solution {
public:
    void reverseString(vector<char>& s)//头尾指针 
    {
        int begin = 0;
        int end = s.size() - 1;

        while(begin < end)
        {
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }
};
