class MyHashMap {
public:
    vector<pair<int,int>>v;
    MyHashMap() {
        v.resize(1e6+1,{0,-1});
    }
    
    void put(int key, int value) {
        v[key].second=value;
    }
    
    int get(int key) {
        return v[key].second;
    }
    
    void remove(int key) {
        v[key].first=0;
        v[key].second=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */