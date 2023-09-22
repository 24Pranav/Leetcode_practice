class Solution {
public:
    using ll=long long;
    int minFlips(int a, int b, int c) {
        ll flip=0;
        while(a!=0 || b!=0 || c!=0)
        {
            if((c&1)==0)
            {
                if((a&1)==1)
                    flip++;
                if((b&1)==1)
                    flip++;
            }
            else if((c&1)==1)
            {
                if((a&1)!=1 && (b&1)!=1)
                    flip++;
                    
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return (int)flip;
    }
};