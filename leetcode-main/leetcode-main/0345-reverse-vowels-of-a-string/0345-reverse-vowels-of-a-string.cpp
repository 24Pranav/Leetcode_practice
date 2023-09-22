class Solution {
public:
    string reverseVowels(string s) {
        stack<char> v;
        string ans="";
        unordered_map<char,int> map;
        map['a']++;map['e']++;map['i']++;map['o']++;map['u']++;
        map['A']++;map['E']++;map['I']++;map['O']++;map['U']++;
        for(char x:s)
        {
            if(map[x]) v.push(x);
        }
        for(char x:s)
        {
            if(map[x])
            {
                ans+=v.top();
                v.pop();
            }
            else
            ans+=x;
        }
        return ans;
    }
};