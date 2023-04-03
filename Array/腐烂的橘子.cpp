class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        int ret = 0;
        //用来标识遍历到的位置四周
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};

        //将腐烂的橘子位置入队列
        queue<pair<int,int>> q;

        //当前新鲜橘子的数目
        int fresh_ori = 0;

       

        //常规
        //遍历grip,如果有个新鲜橘子的周围全是单元格，则不可能
        //同时记录新鲜橘子的数目
        //将腐烂橘子的位置入队列
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh_ori++;
                    //查看它的四周是否都是单元格
                    int flag = 1;//假设全是单元格
                    for(int k = 0; k < 4; k++)
                        if(i+drow[k]>=0 && i+drow[k]<row && j+dcol[k]>=0 &&j+dcol[k]<col)
                        {
                            if(grid[i+drow[k]][j+dcol[k]]!=0)
                            {
                                flag = 0;
                                break;
                            }
                        }
                    if(flag == 1) return -1;
                }
                else if(grid[i][j] == 2)
                    q.push(make_pair(i,j));
            }
        }

        //如果没有新鲜橘子
        if(fresh_ori == 0)
            return ret;
        //如果没有腐烂橘子
        if(q.empty())
            return -1;
        //由于每一层的腐烂橘子是同时扩散的，所以必须在一层腐烂橘子都扩散完之后，才能ret++
        int initNum = q.size();//每层的腐烂橘子
        //BFS 将队头坐标 向四周扩散，将新鲜橘子腐烂，并将新的腐烂橘子坐标入队列
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            
            //将腐烂橘子向四周扩散
            for(int k = 0; k < 4; k++)
            {
                if(x+drow[k]>=0&&x+drow[k]<row&&y+dcol[k]>=0&&y+dcol[k]<col&&
                   grid[x+drow[k]][y+dcol[k]] == 1)
                   {
                        fresh_ori--;
                        grid[x+drow[k]][y+dcol[k]] = 2;
                        q.push(make_pair(x+drow[k],y+dcol[k]));
                   }
            }
            q.pop();
            
            initNum--;
            //若这一层的腐烂橘子没出完，就已经没有新鲜橘子
             if(fresh_ori == 0 && initNum != 0)
             {
                ret++;
                break;
             }
             //若一层的腐烂橘子出完队列，时间增加
            if(initNum == 0)
            {
                ret++;
                initNum = q.size();
            }
             if(fresh_ori == 0)
                break;
        }
        //只有一行或一列可能会导致
        if(fresh_ori != 0)
            return -1;
        return ret;
    }
    
};
