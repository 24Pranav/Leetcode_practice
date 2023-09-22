class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int left=1;
        sort(piles.begin(),piles.end());
        int right=piles[n-1]; // Max answer can be largest element of piles
        int res=right;
        while(left<=right)
        {
            int k=left+(right-left)/2;
            long long hours=0;
            for(auto x:piles)
                hours+=ceil(1.0 * x/k);
            if(hours<=h)
            {
                res=min(res,k);
                right=k-1;
            }
            else
                left=k+1;
        }
        return res;
    }
    
};