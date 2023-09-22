class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        
    }
    
     bool book(int start, int end) {
    mp[start]++;
    mp[end]--;
    int sum=0;
    for(auto x:mp)
    {
        sum+=x.second;
        if(sum>=2)
        {   //If sum > 2 means false therefore we have to remove the entry
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */