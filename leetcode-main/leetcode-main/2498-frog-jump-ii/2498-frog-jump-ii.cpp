class Solution {
public:
//     bool isPossible(vector<int> &nums,int k)
//     {
//  unordered_set<int> visited;
        
//         //first frog jump
//         int i = 1, cur = 0, prev = 0;
//         while(i < nums.size()){
//             if((nums[i] - nums[cur])>k){
//                 if(prev != cur && visited.insert(prev).second) cur = prev;
//                 else return false;
//             }
//             else prev = i++;
//         }
        
//         //2nd frog jump
//         cur = 0; prev = 0; i = 1;
//         while(i < nums.size()){
//             if(visited.find(i) != visited.end()){
//                 ++i; continue;  
//             }
            
//             if((nums[i] - nums[cur])>k){
//                 if(prev != cur) cur = prev;
//                 else return false;
//             }
//             else prev = i++;
//         }
        
//         return true;
//     }
//     int maxJump(vector<int>& stones) {
//         sort(stones.begin(),stones.end());
//         int left=0;
//         int right=*max_element(stones.begin(),stones.end());
//         int ans;
//         while(left<=right)
//         {
//             int mid=left+(right-left)/2;
//             if(isPossible(stones,mid))
//             {
//                 ans=mid;
//                 right=mid-1;
//             }
//             else
//                 left=mid+1;
//         }
//         return ans;
//     }
    
    //Greey Solution
    int maxJump(vector<int>& stones)
    {
        int n=stones.size();
        int ans=max(stones[1]-stones[0],stones[n-1]-stones[n-2]);
        for(int i=0;i<n;i++)
        {
            if(i-1>0)
                ans=max(ans,stones[i]-stones[i-2]);
        }
        return ans;
    }
};