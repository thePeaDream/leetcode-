class Solution {
public:
    bool isValid(string s)//栈 
    {
        stack<char> st;
        //后进的左括号与遍历到的右括号匹配
        for(char& x:s)
        {
            if(x == '('||x=='['||x == '{')//左括号入栈
                st.push(x);
            else if(st.empty())//如果不是左括号，并且栈为空，说明没有左括号与当前遍历到的右括号匹配
                return false;
            else
            {
                // 后进的左括号与遍历到的右括号匹配，左括号出栈
                if(
                (st.top()=='('&&x == ')')||
                (st.top()=='['&&x == ']')||
                (st.top()=='{'&&x == '}')
                )
                    st.pop();
                else//括号不匹配
                    return false;

            }
        }
        //最后栈为空，说明全部括号已经匹配完，否则还有左括号没有匹配
        return st.empty();
    }
};
