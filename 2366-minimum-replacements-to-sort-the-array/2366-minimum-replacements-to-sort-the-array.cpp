class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        cout << (4%5)<<' ';
        long long ans = 0;
        int prev = nums.back();
        
        for(int i=nums.size()-2;i>=0;i--){
            long k = ceil(nums[i]/(double)prev);
            ans += k-1;
            
            prev = (nums[i]/k);
        }
        return ans;
    }
};