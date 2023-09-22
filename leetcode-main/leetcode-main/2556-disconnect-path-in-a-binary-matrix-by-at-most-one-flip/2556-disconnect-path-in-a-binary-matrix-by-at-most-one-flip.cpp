class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>> &grid)
    {
        if(i==grid.size() || j==grid[0].size() || grid[i][j]==0)
            return false;
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return true;
        grid[i][j]=0;
        return dfs(i,j+1,grid)||dfs(i+1,j,grid);
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        bool x=dfs(0,0,grid);
        grid[0][0]=1;
        bool y=dfs(0,0,grid);
        return !(x && y);
    }
};