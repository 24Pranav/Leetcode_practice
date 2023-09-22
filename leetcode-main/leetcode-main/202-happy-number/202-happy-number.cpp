class Solution {
public:
    bool isHappy(int n) {
        long long sum=0;
        int counter=6;
        while(counter--)
        {
        sum=0;
        while(n)
        {
            sum+=(n%10)*(n%10);
            n/=10;
        }
        if(sum==1) return true;
        n=sum;
        }
        return false;
    }
};