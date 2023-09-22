class Solution {
public:
    string b;
    vector<vector<string>> ans;
    unordered_map<string,int> mpp;
     void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
                reverse(seq.begin(), seq.end());
            return;
        }
        int sz = word.size();
        int steps = mpp[word]; 
        for (int i = 0; i < sz; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        /*
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedlevel;
        usedlevel.push_back(beginWord);
        int level=0;
        vector<vector<string>> ans;
        //BFS
        while(!q.empty())
        {
            vector<string> vec=q.front();
            q.pop();
            if(vec.size()>level)
            {
                level++;
                for(auto x:usedlevel){
                    st.erase(x);}
                usedlevel.clear();
            }
            
            string word=vec.back();
            
            //storing ans
            if(word==endWord)
            {
                if(ans.size()==0)
                    ans.push_back(vec);
                else if(ans[0].size()==vec.size())
                    ans.push_back(vec);
            }
            
            for(int i=0;i<word.size();i++)
            {
                char orig=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)>0)
                    {
                        vec.push_back(word);
                        q.push(vec);
                        //Mark visited
                        usedlevel.push_back(word);
                        vec.pop_back();
                    }
                    
                }
                word[i]=orig;
            }
        }
        return ans;
        */
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        queue<string> q;
        b = beginWord;
        q.push({beginWord});
        
        mpp[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);
        while (!q.empty())
        {

            string word = q.front();
            int steps = mpp[word];
            q.pop();
            
            if (word == endWord)
                break;
            for (int i = 0; i < sz; i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {

                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if (mpp.find(endWord) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};