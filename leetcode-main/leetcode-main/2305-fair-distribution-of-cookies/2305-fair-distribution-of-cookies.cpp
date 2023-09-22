class Solution {
public:
    int n;
    int res=INT_MAX;
    int k1;
    void fun(int i,vector<int> &nums,vector<int> &children)
    {
        if(i>=n)
        {
            res=min(res,*max_element(children.begin(),children.end()));
            return ;
        }
        int cookie=nums[i];
        for(int ii=0;ii<k1;ii++)
        {
            children[ii]+=cookie;
            fun(i+1,nums,children);
            children[ii]-=cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        k1=k;
        vector<int> children(k,0);
        fun(0,cookies,children);
        return res;
    }
};