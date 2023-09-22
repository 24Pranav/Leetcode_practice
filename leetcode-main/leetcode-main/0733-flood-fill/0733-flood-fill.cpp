class Solution {
public:
    void fill(vector<vector<int>>& image, int x, int y, int color, int oldColor,int n, int m)
    {
        if(x<0 || y<0 || x==n || y==m || image[x][y]!=oldColor) return;
        image[x][y]=color;
        fill(image,x,y+1,color,oldColor,n,m);
        fill(image,x+1,y,color,oldColor,n,m);
        fill(image,x,y-1,color,oldColor,n,m);
        fill(image,x-1,y,color,oldColor,n,m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];
        if(color==oldColor) return image; //IMP else infinite recursive call
        fill(image,sr,sc,color,oldColor,image.size(),image[0].size());
        return image;
    }
};