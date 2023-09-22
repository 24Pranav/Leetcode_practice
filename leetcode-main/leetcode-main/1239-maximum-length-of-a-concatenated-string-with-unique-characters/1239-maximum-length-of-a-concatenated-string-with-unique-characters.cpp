#define max(a,b) (a>b)?a:b
class Solution {
public:
    map<string,int> dp;
    bool compare(string &s1,string &s2)
    {
        unordered_map<char,int> mp;
        for(auto &x:s1)
        {
            mp[x]++;
            if(mp[x]>1){
                return true;
            }
        }
        
        for(auto &x:s2){
            mp[x]++;
            if(mp[x]>1){
                return true;
            }
        }
        return false;
    }
    int fun(int i,vector<string> &arr,string temp)
    {
        if(i>=arr.size())
            return temp.size();
        int take=0;
        int skip=0;
        if(dp.find(temp)!=dp.end())
            return dp[temp];
        if(compare(temp,arr[i]))
        {
        skip=fun(i+1,arr,temp);
        }
        else
        {
        //include
        take=fun(i+1,arr,temp+arr[i]);
        //exclude
        skip=fun(i+1,arr,temp);
        }
        return dp[temp]=max(take,skip);
    }
    int maxLength(vector<string>& arr) {
        string temp="";
        return fun(0,arr,temp);
    }
};