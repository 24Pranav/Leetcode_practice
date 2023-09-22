#define pi pair<int,int>
#define pb push_back
class SnapshotArray {
public:
    unordered_map<int,vector<pi>> mp;
    int snapp;
    vector<int> vec;
    SnapshotArray(int length) {
        snapp=0;
        for(int i=0;i<length;i++)
        {
            //snapp,index
            mp[i].pb({0,0});
        }
    }
    
    void set(int index, int val) {
        mp[index].pb({snapp,val});
        // mp[snapp]=vec;
    }
    
    int snap() {
        return snapp++;
    }
    
    int get(int index, int snap_id) {
        // return mp[snap_id][index];
        pair<int,int> p{snap_id,1e9};
        auto x=upper_bound(mp[index].begin(),mp[index].end(),p);
        x--;
        return x->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */