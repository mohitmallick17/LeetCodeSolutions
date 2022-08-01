class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int s=0;
        mp[0]=-1;
        int ans=0;
        int prev=-2;
        
        for(int i=0;i<nums.size();i++){
            s += nums[i];
            // cout << s << " : ";
            if(mp.find(s-target) != mp.end()){
                if(mp[s-target] >= prev)ans++, prev=i;
                // cout << s-target << ' ' << prev;
            }
            mp[s]=i;
            // cout << '\n';
        }
        return ans;
    }
};