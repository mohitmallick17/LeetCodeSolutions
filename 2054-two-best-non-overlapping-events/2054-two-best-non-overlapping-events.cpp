class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans=0, maxi=0;
        sort(events.begin(), events.end());
        
        map<int, int> mp;
        for(int i=events.size()-1;i>=0;i--){
            int s=events[i][0], e=events[i][1], val=events[i][2];
            auto it = mp.upper_bound(e);
            maxi = max(maxi, val);
            mp[s]=maxi;
            if(it == mp.end())
                ans = max(ans, maxi);
            else
                ans = max(ans, val + it->second);
        }
        return ans;
    }
};