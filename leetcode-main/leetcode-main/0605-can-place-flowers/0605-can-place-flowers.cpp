class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        // // if only one element or only two elements in the array
        // if((nums.size()==1 && n==1 && nums[0]==0) || (nums.size()==2 && n==1 && (nums[0]==0 && nums[1]==0) ) )
        //     return true;
        // if(nums.size()>2)
        // {
        //     // first 2 elements  0
        //     if(nums[0]==0 && nums[1]==0)
        //     {
        //         nums[0]=1;
        //         n--;
        //     }
        //     // last 2 elements 0
        //     if(nums[nums.size()-1]==0 && nums[nums.size()-2]==0)
        //     {
        //         nums[nums.size()-1]=1;
        //         n--;
        //     }
        // }
        // for(int i=1;i<nums.size()-1;i++)
        // {
        //     if(nums[i-1]==0 && nums[i+1]==0 && nums[i]==0)
        //     {
        //         cout<<i<<" ";
        //         nums[i]=1;
        //         n--;
        //     }
        // }
        // return n<=0;
        
        //Aletrnate solution
        nums.insert(nums.begin(),0);
        nums.push_back(0);
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i-1]==0 && nums[i+1]==0 && nums[i]==0)
            {
                cout<<i<<" ";
                nums[i]=1;
                n--;
            }
        }
        return n<=0;
    }
};