class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n % k != 0)return false;
        map<int, int> mp;
        for(auto &x:nums)mp[x]++;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            int key = it->first, freq=it->second;
            if(freq==0)continue;
            
            for(int i=0;i<k;i++){
                if(mp[key+i] < freq)return false;
                mp[key+i]-=freq;
            }
        }
        return true;
    }
};