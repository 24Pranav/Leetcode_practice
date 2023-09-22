#define pb push_back
class RandomizedSet {
    unordered_map<int,int> map;
    vector<int> arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val)!=map.end())
            return false;
        arr.pb(val);
        map[val]=arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val)==map.end()) return false;
        int last=arr.back(); //IMP
        map[last]=map[val];
        arr[map[val]]=last;
        arr.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        int size=arr.size();
        return arr[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */