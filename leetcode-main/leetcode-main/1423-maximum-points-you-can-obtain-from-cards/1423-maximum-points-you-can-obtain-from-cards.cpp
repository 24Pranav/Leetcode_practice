class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //Sliding Window Technique
        int n=cardPoints.size();
        int tsum=0;
        int maxsum=0;
        int ksum=0;
        for(auto x:cardPoints)
            tsum+=x;
        int i=0;
        for(i=0;i<n-k;i++)
        {
            ksum+=cardPoints[i];
        }
        maxsum=max(maxsum,tsum-ksum);
        int x=0;
        for(;i<n;i++,x++)
        {
            ksum+=cardPoints[i];
            ksum-=cardPoints[x];
            maxsum=max(maxsum,tsum-ksum);
        }
        return maxsum;
    }
};