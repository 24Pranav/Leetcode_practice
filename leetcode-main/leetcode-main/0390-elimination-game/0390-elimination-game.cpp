class Solution {
public:
    int lastRemaining(int n) {
        int diff=1,direction=0,start=1;
        while(n>1)
        {
            if(n&1 || direction==0) // n is odd or if n is odd the direction from left to right
            {
                start+=diff;
            }
            n/=2;
            diff*=2;
            direction=!direction;
        }
        return start;
    }
};