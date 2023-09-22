class Solution {
public:
     string reverseWords(string s) {
        stack<char> st;
        string result;
        string res;
        while(s[0]==' ')
        {
         s.erase(0,1);
        }
        for(auto x:s)
        {
            st.push(x);
        }
        vector<string> v;
        while(!st.empty())
        {
         if(st.top()==' ')
         {
            st.pop();
            reverse(result.begin(),result.end());
            v.push_back(result);
               result="";
         }
         result+=st.top();
         st.pop();
        }
        reverse(result.begin(),result.end());
        v.push_back(result);
        result="";
        for(auto &x:v)
         {
            if(x.back()==' ')
               {
                  x.pop_back();
               }
            result+=x;
            if(result.back()==' ') result.pop_back();
            result+=" ";
         }
         if(result[0]==' ') result.erase(0,1);
         result.pop_back();
        return result;
    }
};