//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Code here
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends