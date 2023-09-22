#define pb push_back
#define pbb pop_back
class Solution {
//Prince Chaurasia
//https://leetcode.com/princeforcode/
public:
    bool isSafe(int row,int col, vector<string> &board, int n,vector<int> left, vector<int> upper, vector<int> lower)
    {
        if(left[row]==0 && lower[row+col]==0 && upper[(n-1)+(row-col)]==0) return true;
        return false;
    }
public:
    void solve(int col,vector<string> &board, vector<vector<string>> &ans, int n, vector<int> &left,vector<int> &upper ,vector<int> &lower)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n,left,upper,lower))
            {
                left[row]=1;
                lower[row+col]=1;
                upper[(n-1)+(row-col)]=1;
                board[row][col]='Q';
                solve(col+1,board,ans,n,left,upper,lower);
                board[row][col]='.';
                left[row]=0;
                lower[row+col]=0;
                upper[(n-1)+(row-col)]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int> left(n,0);
        vector<int> upperdiag(2*n - 1,0);
        vector<int> lowerdiag(2*n - 1,0);
        solve(0,board,ans,n,left,upperdiag,lowerdiag);
        return ans;
    }
};