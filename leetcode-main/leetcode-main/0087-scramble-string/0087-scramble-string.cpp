class Solution {
public:
    unordered_map<string,bool> dp;
    bool fun(string s1, string s2)
    {
        //Base Case
        if(s1.size()==1 || s1==s2)
            return s1==s2;
        string k=s1+s2;
        if(dp.find(k)!=dp.end())
            return dp[k];
        int n=s1.size();
        
        //Avoid necessary Call 
        //return false if frequency of elements are not equal
        vector<int> cs1(26),cs2(26);
        for(int i=0;i<n;i++)
        {
            cs1[s1[i]-'a']++;
            cs2[s2[i]-'a']++;
        }
        if(cs1!=cs2)
            return dp[k]=false;
        
        for(int i=1;i<s1.size();i++)
        {
            //(first half , first half) , (second half ,second half)
            //(first half, second half) ,(second half, first half) //Flip Case
            if((fun(s1.substr(0,i),s2.substr(0,i)) && fun(s1.substr(i),s2.substr(i))) || ( fun(s1.substr(0,i),s2.substr(n-i) ) && fun(s1.substr(i),s2.substr(0,n-i) ) ) ) 
                return dp[k]=true;
        }
        return dp[k]=false;
    }
    bool isScramble(string s1, string s2) {
        return fun(s1,s2);
    }
};