class Solution {
    int atMaxK(vector<int>& v, int k){
        unordered_map<int, int> mp;
        int res=0;
        for(int s=0, e=0;e<v.size();e++){
            mp[v[e]]++;
            
            while(s<e and mp.size() > k){
                mp[v[s]]--;
                if(mp[v[s]]==0)mp.erase(v[s]);
                s++;
            }
            if(mp.size()<=k)
                res += e-s+1;
        }
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int K) {
        return atMaxK(nums, K) - atMaxK(nums, K-1);
    }
};