#define pb push_back
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int t,d,l,r;
        int dir=0;
        t=0,l=0;
        d=n-1;
        r=n-1;
        int cnt=1;
        while(t<=d && l<=r)
        {
            vector<int> temp;
            if(dir==0)
            {
                for(int i=l;i<=r;i++)
                {
                    matrix[t][i]=cnt++;
                }
                t++;
                dir=(dir+1)%4;
            }
            else if(dir==1)
            {
                for(int i=t;i<=d;i++)
                {
                    matrix[i][r]=cnt++;
                }
                r--;
                dir=(dir+1)%4;
            }
            else if(dir==2)
            {
                for(int i=r;i>=l;i--)
                {
                    matrix[d][i]=cnt++;
                }
                d--;
                dir=(dir+1)%4;
            }
            else if(dir==3)
            {
                for(int i=d;i>=t;i--)
                {
                   matrix[i][l]=cnt++;
                }
                l++;
                dir=(dir+1)%4;
            }
        }
        return matrix;
    }
};