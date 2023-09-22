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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // for(int i=0;i<n;i++)
        //     for(int j=0;j<m;j++)
        //         cout<<matrix[i][j]<<" ";
        vector<int> heights(m,0);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {heights[j]++;
                }
                
                if(matrix[i][j]=='0')
                    heights[j]=0;
            }
            cout<<endl;
            int ans=largestRectangleArea(heights);
            maxi=max(maxi,ans);
        }

        return maxi;
    }
};