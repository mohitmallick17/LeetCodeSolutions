class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int &x:nums)mp[x]++;
        int n=nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto &x:mp)
            bucket[x.second].push_back(x.first);

        vector<int> res;
        for(int i=bucket.size()-1;i>=0 and res.size() < k;i--){
            for(int j=0;j<bucket[i].size() and res.size() < k;j++){
                res.push_back(bucket[i][j]);
            }
        }
        return res;
    }
};