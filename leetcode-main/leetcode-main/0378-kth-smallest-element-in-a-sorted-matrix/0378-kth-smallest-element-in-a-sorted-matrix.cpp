class Solution {
public:
    int rankof(vector<vector<int>> &matrix, int mid)
    {
        int rank=0;
        int n=matrix.size();
        int i=n-1, j=0;
        while(i>=0 && j<n)
        {
            if(matrix[i][j]>mid)
                i--;
            else
            {
                rank+=i+1;
                j++;
            }
        }
        return rank;
        
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<int> pq;
//         for(auto &x:matrix)
//             for(auto &j:x)
//             {
//                 pq.push(j);
//                 if(pq.size()>k)
//                     pq.pop();

//             }
//         return pq.top();
        int row=matrix.size();
        int col=matrix[0].size();
        int left=matrix[0][0];
        int right=matrix[row-1][col-1];
        int ans;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int rank=rankof(matrix,mid);
            if(rank<k)
            {
                ans=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        cout<<rankof(matrix,13)<<endl;
        return left;
        
    }
};