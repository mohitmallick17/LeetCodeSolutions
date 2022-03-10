class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, pair<int, int>> dp;
        int longestLIS=0, res=0;
        
        for(int i=n-1;i>=0;i--){
            int maxLen = 1, maxCnt = 1;
            for(int j=i+1;j<n;j++){
                int len = dp[j].first, cnt = dp[j].second;
                if(nums[j] > nums[i]){
                    if(len + 1 > maxLen){
                        maxLen = len+1;
                        maxCnt = cnt;
                    }else if(len + 1 == maxLen){
                        maxCnt += cnt;
                    }
                }
            }
            if(longestLIS < maxLen){
                longestLIS = maxLen;
                res = maxCnt;
            }else if(longestLIS==maxLen)
                res += maxCnt;
            dp[i] = {maxLen, maxCnt};
        }
        return res;
    }
};