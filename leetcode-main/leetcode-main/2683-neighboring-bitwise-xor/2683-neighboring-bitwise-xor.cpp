class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        /*
        int n=derived.size();
        vector<int> arr(n,0);
        
        for(int i=0;i<n-1;i++)
        {
            arr[i+1]=arr[i]^derived[i];
        }
        // for the last element
        if(arr[n-1]^arr[0]!=derived[n-1])
            return false;
        for(int i=0;i<n-1;i++)
            if(arr[i]^arr[i+1]!=derived[i])
                return false;
        return true;
        */
        
        //Alternate Solution
        //orignal arr [a,b,c,d]
        //derived [a^b,b^c,c^d,d^a] , xor of all 0
        
        for(int i=1;i<derived.size();i++)
            derived[0]^=derived[i];
        return derived[0]==0;
    }
};