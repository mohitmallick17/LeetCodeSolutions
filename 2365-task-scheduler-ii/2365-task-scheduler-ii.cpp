class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> mp;
        
        long long ans=0;
        for(int &t:tasks){
            if(mp.find(t)==mp.end())
                mp[t] = ++ans;
            else
                mp[t] = ans = max(ans, mp[t]+space)+1;
        }
        return ans;
    }
};