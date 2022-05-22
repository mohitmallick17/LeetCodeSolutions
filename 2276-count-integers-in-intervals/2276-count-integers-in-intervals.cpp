class CountIntervals {
    map<int, int> mp;
    int cnt;
public:
    CountIntervals() {
        cnt=0;
    }
    
    void add(int left, int right) {
        auto it = mp.upper_bound(left);
        if(it!=begin(mp) and prev(it)->second>=left)it=prev(it);
        
        while(it != end(mp) and it->first <= right){
            left = min(left, it->first);
            right = max(right, it->second);
            cnt -= it->second - it->first + 1;
            mp.erase(it++);
        }
        cnt += right-left+1;
        mp[left]=right;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */