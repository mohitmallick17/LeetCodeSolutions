class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<int, int>> hash(n);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[j] - nums[i];
                if(hash[j].find(diff) != hash[j].end())
                    hash[i][diff] = hash[j][diff] + 1;
                else
                    hash[i][diff] = 1;
                ans = max(ans, hash[i][diff]);
            }
        }
        return ans+1;
    }
};