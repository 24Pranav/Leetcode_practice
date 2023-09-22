class Solution {
public:
    bool fun(int i,int j,vector<vector<int>>& matrix,int  n, int m,int element)
    {
        if(i==n-1 || j==m-1)
            return matrix[i][j]=element;
        if(i<n && j<m)
        {
            if(matrix[i][j]!=element) return false;
            fun(i+1,j+1,matrix,n,m,element);
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // bool diag1=false;
        // bool diag2=false;
        // for(int i=0;i<m;i++)
        //     diag1=fun(0,i,matrix,n,m,matrix[0][i]);
        // for(int i=0;i<n;i++)
        //     diag2=fun(i,0,matrix,n,m,matrix[i][0]);
        // return diag1 && diag2;
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]!=matrix[i-1][j-1])
                    return false;
            }
        return true;
    }
};