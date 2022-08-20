class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> mp;
        for(auto &x:stones)mp[x]++;
        
        int ans=0;
        for(auto &j:jewels){
            ans += mp[j];
        }
        return ans;
    }
};