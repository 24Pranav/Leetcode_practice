class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int count=0;
        for(int j=n-1;j>=0;j--)
        {
            int left=0;
            int right=j-1;
            while(left<right)
            {
                if(arr[left]+arr[right]>arr[j])
                {
                    count+=right-left;
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return count;
    }
};