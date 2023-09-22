class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> map;
        int ans = 0;
        for(auto x:tasks){
            map[x] += 1;
        }

        for(auto x:map){
            int temp = x.second;
            if(temp < 2) return -1;
            else if(temp == 2) ans++;
            else if(temp >= 3){
                ans += temp/3;
                if(temp%3 != 0) ans++;
            }
        }
        return ans;
    }
};