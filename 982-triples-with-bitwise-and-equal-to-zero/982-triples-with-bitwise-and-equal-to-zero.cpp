class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int &a:nums){
            for(int &b:nums)
                mp[a&b]++;
        }
        int count = 0;
        
        for(int &a:nums){
            for(auto &[k, v]:mp){
                if((a & k) == 0)
                    count += v;
            }
        }
        return count;
    }
};