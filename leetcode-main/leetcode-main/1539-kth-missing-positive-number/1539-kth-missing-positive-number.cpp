class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // unordered_map<int,int> map;
        // for(auto x:arr)
        //     map[x]++;
        // int n=arr.size();
        // int i=1;
        // while(k)
        // {
        //     if(!map[i])
        //         k--;
        //         i++;
        // }
        // return i-1;
        
    for(auto &x:arr)
        if(x<=k)
            k++;
        return k;
    }
};