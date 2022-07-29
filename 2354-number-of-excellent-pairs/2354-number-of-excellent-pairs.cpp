class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<long long> cnt(32, 0);
        for(auto &n:unordered_set<int>(begin(nums), end(nums))){
            cnt[__builtin_popcount(n)]++;
        }
        long long ans=0;
        
        for(int i=1;i<30;i++){
            for(int j=1;j<30;j++){
                if(i+j >= k)
                    ans += cnt[i]*cnt[j];
            }
        }
        return ans;
    }
};