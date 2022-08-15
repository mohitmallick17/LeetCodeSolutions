class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a){
        long long ans=0, mod=1e9 + 7;
        sort(a.begin(), a.end());
        unordered_map<int, long long> mp;
        
        for(int i=0;i<a.size();i++){
            mp[a[i]]=1;
            for(int j=0;j<i;j++){
                if(a[i] % a[j] == 0){
                    mp[a[i]] = (mp[a[i]] + (mp[a[j]] * mp[a[i]/a[j]])) % mod;
                }
            }
            ans = (ans + mp[a[i]]) % mod;
        }
        return ans;
        
    }
};