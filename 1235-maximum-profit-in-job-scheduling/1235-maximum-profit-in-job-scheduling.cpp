struct item{
    int st;
    int et;
    int p;
    item(int s, int e , int pp) {
        st=s;
        et=e;
        p=pp;
    }
    bool operator<(item &b){
        return et < b.et;
    }
};
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<item> v;
        
        for(int i=0;i<n;i++){
            v.push_back(item(startTime[i], endTime[i], profit[i]));
        }
        sort(v.begin(), v.end());
        map<int, int> mp; // key: endTime, val: profit
        mp[0] = 0;
        
        for(int i=0;i<n;i++){
            auto it = mp.upper_bound(v[i].st);
            it--;
            int val = v[i].p + it->second;
            if(val > mp.rbegin()->second){
                mp[v[i].et] = val;
            }
        }
        
        return mp.rbegin()->second;
    }
};