class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++)
            v[i] = {endTime[i], startTime[i], profit[i]};
        sort(v.begin(), v.end());
        map<int,int> mp; // end - profit: until point end, max profit I can make
        mp[0]=0;
        
        for(int i=0;i<n;i++){
            int s=v[i][1], e=v[i][0], p=v[i][2];
            int pick=0;
            int not_pick = mp.rbegin()->second;
            if(mp.rbegin()->first <= s){
                // extend the prev job
                pick = p + mp.rbegin()->second;
            }else{
                // can't extend the prev job, so binary search the last possible job
                auto it = mp.upper_bound(s); // find someone > start
                it--; // decrease it, will point to someone <= start
                pick = p + it->second;
            }
            mp[e] = max(pick, not_pick);
        }
        // for(auto &x:mp)cout << x.first << ' ' << x.second << '\n';
        return mp.rbegin()->second;
    }
};