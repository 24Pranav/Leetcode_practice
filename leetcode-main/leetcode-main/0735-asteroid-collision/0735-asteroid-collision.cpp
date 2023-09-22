class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++)
        {
            int x=asteroids[i];
            while(!st.empty() && x<0 && st.top()>0)
            {
                int dir=x+st.top(); //sum >0 -> else <-
                if(dir<0)
                {
                st.pop();
                }
                else if(dir>0)
                    x=0;
                else if(dir==0)
                {
                    st.pop();
                    x=0;
                }
                else
                    st.push(x);
                    
            }
            if(x!=0)
                st.push(x);
        }
        vector<int> ans(st.size());
        int i=st.size()-1;
        while(!st.empty())
        {
            ans[i--]=st.top();
            st.pop();
        }
        return ans;
    }
};