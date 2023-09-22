class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0)
        {
            n=abs(n);
            x=1/x;
        }
        else if(n%2==0)
        {
            return myPow(x*x,n/2); //If even (x*x)^n/2 Ex 2^4 will be (2*2)^2
        }
        return x*myPow(x,n-1); //If Odd x*(x)^n-1 Ex 2^5 will be (2*2)^4
    }
};