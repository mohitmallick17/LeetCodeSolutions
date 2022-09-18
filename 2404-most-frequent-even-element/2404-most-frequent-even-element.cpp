class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans=-1, maxf=0;
        for(auto &x:nums){
            if(x % 2 == 0){
                mp[x]++;
            
                if(mp[x] > maxf){
                    ans=x;
                    maxf=mp[x];
                }else if(mp[x]==maxf)
                    ans = min(ans, x);
                
            }
        }
        return ans;
    }
};