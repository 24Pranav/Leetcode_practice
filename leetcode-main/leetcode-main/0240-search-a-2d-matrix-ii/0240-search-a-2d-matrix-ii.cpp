class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // bool ans=false;
        // for(auto &mat:matrix)
        // {
        //     ans|=binary_search(mat.begin(),mat.end(),target);
        //     if(ans)
        //         return true;
        // }
        // return ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int left=0;
        int right=col-1;
        while(right>=0 && left<row)
        {
            if(matrix[left][right]==target)
                return true;
            if(matrix[left][right]>target)
                right--;
            else
                left++;
        }
        return false;
    }
};