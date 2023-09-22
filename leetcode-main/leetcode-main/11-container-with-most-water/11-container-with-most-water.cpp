class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        if(n==1) return n;
        int x=0;
        int y=n-1;
        int area=0;
        while(x<y)
        {
            int l=min(height[x],height[y]);
            area=max(l*(y-x),area);
            if(l==height[x]) x++; else y--;
        }
        return area;
    }
};