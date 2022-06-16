class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        
        for(auto &s:strs){
            vector<int> key(26, 0);
            for(char &c:s)key[c-'a']++;
            
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto &x:mp)
            res.push_back(x.second);
        return res;
    }
};