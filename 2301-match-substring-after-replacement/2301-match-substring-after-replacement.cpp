class Solution {
    unordered_map<char, unordered_set<char>> st;
    
    bool check(int start, string &s, string &sub){
        for(int i=start,j=0;j<sub.size();i++,j++){
            if(s[i]!=sub[j] and (st[sub[j]].count(s[i]) == 0))return false;        
        }
        return true;
    }
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        for(auto &x:mappings)
            st[x[0]].insert(x[1]);
        
        for(int i=0;i<s.size()-sub.size()+1;i++){
            if(check(i, s, sub))return true;
        }
        return false;
    }
};