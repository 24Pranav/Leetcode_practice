class Solution {
public:
    bool check(string str1, string str2, unordered_map<char,int> &map)
    {
        for(int i=0;i< str1.size() && str2.size(); i++)
        {
            if(map[str1[i]]<map[str2[i]])
            {
                return true;
            }
            else if(map[str1[i]]==map[str2[i]])
                continue;
            else
                return false;
            // else
            // {
            //     cout<<map[str1[i]]<<" "<<map[str2[i]]<<" "<<endl;
            //     cout<<"--"<<i<<"--"<<endl;
            //     return false;
            // }
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>  map;
        int i=0;
        for(auto &x:order)
            map[x]=++i;
        for(int i=1;i<words.size();i++)
        {
            bool ans=check(words[i-1],words[i],map);
            // cout<<ans<<" ";
            if(!ans)
                return ans;
        }
        return true;
    }
};