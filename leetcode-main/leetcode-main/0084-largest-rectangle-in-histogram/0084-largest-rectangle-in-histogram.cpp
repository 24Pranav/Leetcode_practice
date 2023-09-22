class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int leftsmall[n], rightsmall[n];
        for(int i=0;i<n;i++)
        {
        while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            
            if(st.empty())
                leftsmall[i]=0;
            else
                leftsmall[i]=st.top()+1;
            st.push(i);
        }
        
        while(!st.empty())
            st.pop(); // Clearing the stack
        
         for(int i=n-1;i>=0;i--)
        {
        while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            
            if(st.empty())
                rightsmall[i]=n-1;
            else
                rightsmall[i]=st.top()-1;
            st.push(i);
        }
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int area=heights[i]*(rightsmall[i]-leftsmall[i]+1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};