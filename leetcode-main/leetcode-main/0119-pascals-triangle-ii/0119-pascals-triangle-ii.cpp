class Solution {
public:
    using ll=long double;
    ll calc(int n, int r)
    {
        ll num=1;
        ll den=1;
        for(int i=r;i>=1;i--)
        {
            num*=(ll)n;
            n--;
            num/=(ll)i;
        }
        return num;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,0);
        for(int i=0;i<=rowIndex;i++)
        {
            ll x=calc(rowIndex,i);
            ans[i]=(int)(x+0.5); //round of
        }
        return ans;
    }
};