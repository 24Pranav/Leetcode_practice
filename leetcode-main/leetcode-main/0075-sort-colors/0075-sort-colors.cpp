class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int mid=0;
        int high=n-1;
        while(mid<=high)
        {
            if(arr[mid]==0)
            {
                swap(arr[l],arr[mid]);
                l++;
                mid++;
            }
            else if(arr[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};