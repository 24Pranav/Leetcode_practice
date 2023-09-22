class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n+1);
        
        //first ugly number
        t[1]=1;
        
        int i2=1;
        int i3=1;
        int i5=1;
        
        for(int i=2;i<=n;i++)
        {
            int i2num=t[i2]*2;
            int i3num=t[i3]*3;
            int i5num=t[i5]*5;
            
            int mini=min({i2num,i3num,i5num});
            
            if(i2num==mini)
                i2++;
            if(i3num==mini)
                i3++;
            if(i5num==mini)
                i5++;
            
            //minimum will be the ugly number
            t[i]=mini;
        }
        return t[n];
    }
};