class ParkingSystem {
public:
    map<int,int> mp;
    ParkingSystem(int big, int medium, int small) {
        mp[0]=big;
        mp[1]=medium;
        mp[2]=small;
    }
    
    bool addCar(int carType) {
        if(mp[carType-1]>0)
        {
            mp[carType-1]--;
            return true;
        }
        else
            return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */