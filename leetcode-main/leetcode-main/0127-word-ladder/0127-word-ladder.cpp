class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto &x:wordList)
            st.insert(x);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        //BFS
        while(!q.empty())
        {
            auto it=q.front();
            string word=it.first;
            int step=it.second;
            q.pop();
            if(word==endWord)
                return step;
            for(int i=0;i<word.size();i++)
            {
                char orig=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=orig;
            }
        }
        return 0;
    }
    
};