class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x=__builtin_popcount(n);
        if(n<0)
            return false;
        if(x==1)
            return true;
        return false;
    }
};