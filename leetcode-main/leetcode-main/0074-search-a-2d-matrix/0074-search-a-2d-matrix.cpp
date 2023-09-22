class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // bool ans=false;
        // for(auto mat:matrix)
        //     ans|=binary_search(mat.begin(),mat.end(),target);
        // return ans;
        int r=matrix.size();
        int c=matrix[0].size();
        int left=0;
        int right=(r*c)-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int row=mid/c; // to find i (row)
            int col=mid%c; // to find j (col)
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
    }
};