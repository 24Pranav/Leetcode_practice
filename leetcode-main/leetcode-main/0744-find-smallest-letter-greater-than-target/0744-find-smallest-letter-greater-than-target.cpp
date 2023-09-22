class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans='z';
        bool found=false;
        for(auto &x:letters)
        {
            if(x>target)
            {
                found=true;
                // cout<<x<<" ";
                if(x<ans)
                    ans=x;
            }
        }
        if(!found)
            return letters[0];
        return ans;
    }
};