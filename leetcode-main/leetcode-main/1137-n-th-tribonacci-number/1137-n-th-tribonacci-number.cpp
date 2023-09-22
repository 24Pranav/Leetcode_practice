class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return n;
        int a=0;
        int b=1;
        int c=1;
        int ans=1;
        if(n>0)
        for(int i=0;i<n-2;i++)
        {
            ans=a+b+c;
            a=b;
            b=c;
            c=ans;
        }
        return ans;
    }
};