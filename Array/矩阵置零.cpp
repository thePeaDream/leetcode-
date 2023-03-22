class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)//使用额外空间 
    {
        vector<vector<int>> tmp = matrix;
        for(int row = 0; row < tmp.size();row++)
        {
            for(int col = 0; col < tmp[0].size();col++)
            {
                if(tmp[row][col] == 0)
                {
                    //将所在行和列的所有元素设为0
                    for(int i = 0; i < matrix.size(); i++)
                        matrix[i][col] = 0; //固定第col列
                    for(int i = 0; i < matrix[0].size(); i++)
                        matrix[row][i] = 0;  //固定第row行

                }
            }
        }
    }
};
