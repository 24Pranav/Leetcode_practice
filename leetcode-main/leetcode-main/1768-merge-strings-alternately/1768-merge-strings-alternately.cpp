class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int size=min(word1.size(),word2.size());
        int i;
        for(i=0;i<size;i++)
        {
            ans+=word1[i];
            ans+=word2[i];
        }
        if(i<word1.size())
            ans+=word1.substr(i,word1.size());
        if(i<word2.size())
            ans+=word2.substr(i,word2.size());
        return ans;
    }
};