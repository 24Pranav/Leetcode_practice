class Solution {
public:
    bool fun(int i, int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        if(grid[i][j])
            return true;
        grid[i][j]=2; //Mark Visited
        bool l=fun(i,j-1,grid);
        bool r=fun(i,j+1,grid);
        bool u=fun(i-1,j,grid);
        bool d=fun(i+1,j,grid);
        return l && r && u && d;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    ans+=fun(i,j,grid)?1:0;
                }
            }
        return ans;
    }
};