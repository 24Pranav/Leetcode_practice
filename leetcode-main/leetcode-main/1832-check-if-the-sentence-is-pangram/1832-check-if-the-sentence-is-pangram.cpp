class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26];
        for(auto x:sentence)
        {
            int in=x-'0'-49;
            arr[in]=1;
            // cout<<in<<" ";
        }
        for(int i=0;i<26;i++)
            if(arr[i]!=1) return false;
        return true;
    }
};