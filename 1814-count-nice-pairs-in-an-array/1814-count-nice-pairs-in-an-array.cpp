class Solution {
    int rev(int n){
        int ans=0;
        while(n){
            ans = (ans*10) + n%10;
            n/=10;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, long long> mp;
        long long res=0, mod=1e9 + 7;
        for(long long i=0;i<nums.size();i++){
            int key = nums[i] - rev(nums[i]);
            res = (res + mp[key])%mod;
            mp[key]++;
        }
        return res;
    }
};