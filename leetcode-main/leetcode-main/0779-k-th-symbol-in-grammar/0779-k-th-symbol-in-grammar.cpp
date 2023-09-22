class Solution {
public:
    int fun(int n,int k)
    {
        if(n==1 && n==k)
            return 0;
        int len=pow(2,n-1);
        int mid=len>>1;
        if(k<=mid)
        return fun(n-1,k); // If k lie in first half itself
        else
            return !fun(n-1,k-mid); // If k lies next half so subtract k to first half and flip tha answer 0->1 and 1->0
        
    }
    int kthGrammar(int n, int k) {
        return fun(n,k);
    }
};