class Solution {
public:
    int numRabbits(vector<int>& v) {
        unordered_map<int, int> mp;
        for(auto &x:v)mp[x]++;
        
        int ans=0;
        for(auto &[k, v]:mp){
            int grpLen=k+1;
            int r=v;
            
            ans += grpLen*(ceil(v/(1.0 * grpLen)));
        }
        return ans;
    }
};