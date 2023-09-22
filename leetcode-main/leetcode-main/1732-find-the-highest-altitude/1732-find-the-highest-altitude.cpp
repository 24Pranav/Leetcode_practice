class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int ans=0;
        for(auto &x:gain){
            ans+=x;
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};