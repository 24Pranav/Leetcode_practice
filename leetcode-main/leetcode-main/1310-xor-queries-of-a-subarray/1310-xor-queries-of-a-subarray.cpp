class Solution {
public:
    void print(vector<int> v)
    {
        for(auto x:v)
            cout<<x<<" ";
        cout<<endl;
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> prefix(arr.size()+1,0);
        prefix[0]=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            //Prefix array calculate
            prefix[i]=prefix[i-1]^arr[i];
        }
        print(prefix);
        //prefix of l to r
        // prfix[r]^prefix[l-1]
        for(auto it:queries)
        {
            if(it[0]==0)
                ans.push_back(prefix[it[1]]);
            else
                ans.push_back(prefix[it[1]]^prefix[it[0]-1]);
        }
        return ans;
    }
};