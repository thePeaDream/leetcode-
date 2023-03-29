class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        if(image[sr][sc] == color)//不需要改
            return image;

        if(image[sr][sc] != color)
        {
            //将image[sr][sc]以及和image[sr][sc]相同的相邻格子全置color
            stain(image, sr, sc, color, image[sr][sc]);
        }
        return image;    
    }
private:
    void stain(vector<vector<int>>& image, int sr, int sc, int color, int premise)
    {
        if(sr < 0 || sr >= image.size()) return;
        if(sc < 0 || sc >= image[0].size()) return;
        if(image[sr][sc] != premise) return;

        //该格子满足置color的条件即=premise
        image[sr][sc] = color;

        //将相邻上下左右的=premise的格子置color
        stain(image, sr-1,sc, color, premise);//上       
        stain(image, sr+1,sc, color, premise);//下
        stain(image, sr, sc-1, color, premise);//左
        stain(image, sr, sc+1, color, premise);//右
    }
};
