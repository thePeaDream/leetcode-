class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int ret = 0;
        for(int r = 0; r < grid.size(); r++)
        {
            for(int c = 0; c < grid[0].size(); c++)
            {
                //如果是岛屿，以此为中心向四周扩散，得出该岛屿面积
                if(grid[r][c] == 1)
                {
                    int tmp = Area(grid, r, c);
                    ret = ret > tmp ? ret: tmp;
                }
            }
        }
        return ret;
    }
private:
    int Area(vector<vector<int>>& grid, int curRow,int curCol)
    {
        if(curRow < 0 || curRow == grid.size())
             return 0;
        if(curCol < 0 || curCol == grid[0].size())
            return 0;
        if(grid[curRow][curCol] == 1)
        {
            //注意这个位置置0，否则发生无穷递归
            grid[curRow][curCol] = 0;       
            return Area(grid, curRow-1, curCol)+Area(grid, curRow+1, curCol)
                  +Area(grid, curRow, curCol-1)+Area(grid, curRow, curCol+1)+1;
        }
        return 0;
    }
};
