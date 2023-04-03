class Solution 
{
public:
//   已经知道【与0的距离】的点,向四周扩散，若四周的点不知道，则四周的点更新距离
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)//BFS 
    {
        //创建大小相同的矩阵
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> ret(row, vector<int>(col, -1));
        //还没有搜索到的位置设为-1，表示距离0无穷大
        BFS(mat, ret);
        return ret;
    }
private:
    void BFS(vector<vector<int>>& mat, vector<vector<int>>& ret)
    {
        int row = mat.size();
        int col = mat[0].size();
        //将mat中值为0的点坐标都加入队列
        queue< pair<int, int> > q;
        for(int i = 0; i < mat.size(); i++)
            for(int j = 0; j < mat[0].size();j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push(pair<int,int>(i, j));
                    //同时更新ret中 离0的距离 为0的位置
                    ret[i][j] = 0;
                }
            }

        //队列中已经确认【离0的距离】的点 进行广度优先遍历
        //向四周扩散，如果四周的点为-1，说明没有搜索到
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

            int drow[] = {-1,1,0,0};
            int dcol[] = {0,0,-1,1};
            //ret[x+drow[0]][y+dcol[0]] - 上
            //ret[x+drow[1]][y+dcol[1]] - 下
            //ret[x+drow[2]][y+dcol[2]] - 左
            //ret[x+drow[3]][y+dcol[3]] - 右
            for(int i = 0; i < 4; i++)
            {
                if(x+drow[i]>=0 && x+drow[i] < row && y+dcol[i]>=0&&y+dcol[i]<col
                && ret[x+drow[i]][y+dcol[i]] == -1)
                {
                    //如果这个点是有效的坐标，同时这个位置没有被遍历过
                    //更新这个位置 与0的距离
                    ret[x+drow[i]][y+dcol[i]] = ret[x][y]+1;
                    //同时把它入队列
                    q.push(make_pair(x+drow[i],y+dcol[i]));
                }
            }
            q.pop();
        }

    }
        

};
