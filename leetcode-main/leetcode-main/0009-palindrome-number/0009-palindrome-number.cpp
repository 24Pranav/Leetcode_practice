class Solution {
public:
    long long reverse(int n)
    {
        long long rev=0;
        while(n)
        {
            rev=rev*10+n%10;
            n/=10;
        }
        cout<<rev;
        return rev;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long rev=reverse(x);
        return x==rev;
    }
};