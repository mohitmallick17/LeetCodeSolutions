class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &x:nums){
            if(x % 2 == 0)mp[x]++;
        }
        int ans=-1, maxf=0;
        for(auto &[n,f]:mp){
            if(f > maxf){
                ans=n;
                maxf=f;
            }else if(f==maxf)
                ans = min(ans, n);
        }
        return ans;
    }
};