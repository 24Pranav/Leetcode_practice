class MyCalendarTwo {
public:
    map<int,int> mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
    mp[start]++;
    mp[end]--;
    int sum=0;
    for(auto x:mp)
    {
        sum+=x.second;
        if(sum>=3)
        {   //If sum > 3 means false therefore we have to remove the entry
            //thats why we will dectrease the start entry and inrease the ending entry
            mp[start]--; 
            mp[end]++;
            return false;
        }
    }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */