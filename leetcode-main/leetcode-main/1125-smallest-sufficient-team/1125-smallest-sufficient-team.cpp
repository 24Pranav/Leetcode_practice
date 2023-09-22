class Solution {
public:
 vector<int> v;
    map<string,int> mp;
    int n; int m;
    int x;
    vector<int> pp;
    
    void fun(int id,int s,vector<int>& us){
        if(s >= x){
            if(us.size() < v.size() || v.size() < 1){
                v = us;
            }
            return;
        }
        if(id == n ||(v.size()>0 && us.size() >= v.size()))
            return;
        
        int i;
        if(s & (1 << id))
            fun(id+1,s,us);
        else{
            for(i=0;i<m;i++){
                if(pp[i] & (1 << id)){
                    int p = s | pp[i];
                    us.push_back(i);
                    fun(id+1,p,us);
                    us.pop_back();
                }
            }
        }
    }
    vector<int> smallestSufficientTeam(vector<string>& skills, vector<vector<string>>& pep) {
        n=skills.size();
        m=pep.size();
        
        int i,j;x=1;        
        for(i=0;i<n;i++){
            mp[skills[i]]=i;
            x *= 2; 
        }
        x--;
       
        for(i=0;i<m;i++){
            int y=0;
            
            for(j=0;j<pep[i].size();j++){
                y += (1 << mp[pep[i][j]]);
            }
            pp.push_back(y);
           // cout << y << "\n";
        }
        
        vector<int> bb;
        fun(0,0,bb);
        return v;
    }
};