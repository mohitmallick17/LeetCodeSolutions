class MyCalendarTwo {
    vector<pair<int, int>> events;
    vector<pair<int, int>> overlaps;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto &p:overlaps){
            if(start < p.second and end > p.first)
                return false;
        }
        for(auto &p:events){
            if(start < p.second and end > p.first)
                overlaps.push_back({max(start, p.first), min(end, p.second)});
        }
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */