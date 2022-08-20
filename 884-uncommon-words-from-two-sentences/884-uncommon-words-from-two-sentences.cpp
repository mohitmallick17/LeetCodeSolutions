class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        istringstream iss(s1 + " " + s2);
        while(iss >> s1)mp[s1]++;
        
        vector<string> res;
        for(auto &[k,v]:mp){
            if(v==1)res.push_back(k);
        }
        return res;
    }
};