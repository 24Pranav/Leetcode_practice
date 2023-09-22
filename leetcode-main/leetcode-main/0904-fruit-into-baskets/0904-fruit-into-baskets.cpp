class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        set<int> s;
        for(auto &x:fruits)
            s.insert(x);
        if(s.size()<=2)
            return fruits.size();
        unordered_map<int,int>m;
        int i=0,j=0,ans=0;
        while(j<fruits.size())
        {
            m[fruits[j]]++;
            while(m.size()>2)
            {
                if(m[fruits[i]]==1)
                    m.erase(fruits[i]);
                else
                    m[fruits[i]]--;
                i++;
            }
            
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};