class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
       if(n==1)
           return 1;
        if(n==2)
            return nthPersonGetsNthSeat(n-1)/2;
        return nthPersonGetsNthSeat(n-1);
    }
};