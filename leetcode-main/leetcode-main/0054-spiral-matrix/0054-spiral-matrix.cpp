#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int t,d,l,r;
        int dir=0;
        t=0,l=0;
        d=matrix.size()-1;
        r=matrix[0].size()-1;
        while(t<=d && l<=r)
        {
            if(dir==0)
            {
                for(int i=l;i<=r;i++)
                {
                    ans.pb(matrix[t][i]);
                }
                t++;
            }
            else if(dir==1)
            {
                for(int i=t;i<=d;i++)
                {
                    ans.pb(matrix[i][r]);
                }
                r--;
            }
            else if(dir==2)
            {
                for(int i=r;i>=l;i--)
                {
                    ans.pb(matrix[d][i]);
                }
                d--;
            }
            else if(dir==3)
            {
                for(int i=d;i>=t;i--)
                {
                    ans.pb(matrix[i][l]);
                }
                l++;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};