class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        //构建杨辉三角的行与列
        //行构建
        vector<vector<int>> re;
        re.resize(numRows);
        
        //第n行有n个数（列构建）
        for(int row = 0;row < numRows;row++)
        {
            re[row].resize(row+1);

            //同时每一行的第一列和最后一列必须为1
            //即re[row][0] —— 当前行的第一个数
            //re[row][row] —— 当前行的最后一个数
            re[row][0] = re[row][row] = 1;

            //特殊情况外，每个数是它左上方和右上方数的和
            for(int col = 1; col < row; col++)
                re[row][col] = re[row-1][col-1]+re[row-1][col];
        }
        
        return re;
    }
};
