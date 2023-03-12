class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        //原始的行与列
        int preR = mat.size();
        int preC = mat[0].size();


        //开辟r*c的矩阵
        //即r个 vector<int>
        //每个vector里有c个元素
        vector<vector<int>> re;
        re.resize(r);
        for(int i = 0; i < r; i++)
            re[i].resize(c);
    
        if(preR*preC == r*c)//可行
        {
            //用来填充新开的矩阵
            int row = 0;
            int col = 0;

            //遍历mat,把数据填充到新矩阵
            for(int i = 0; i < preR;i++)
                for(int j = 0; j < preC;j++)
                {
                    re[row][col++]=mat[i][j];
                    if(col == c)
                    {
                        col = 0;
                        row++;
                    }
                }
        }
        else
        {
            return mat;
        }
        return re;

    }
};
