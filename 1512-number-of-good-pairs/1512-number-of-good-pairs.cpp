class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        
        for(int &x:nums){
            if(!mp.count(x))
                mp[x]=1;
            else{
                res += mp[x]++;
            }
        }
        return res;
    }
};