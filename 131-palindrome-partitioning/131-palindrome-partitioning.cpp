class Solution {
    vector<vector<string>> res;
    bool isPalin(string& s){
        for(int i=0, j=s.size()-1;i<j;i++,j--){
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
    void solve(string& s, int start, vector<string>& cur){
        if(start==s.size()){
            res.push_back(cur);
            return;
        }
        
        string t;
        for(int i=start;i<s.size();i++){
            t += s[i];
            if(!isPalin(t))continue;
            cur.push_back(t);
            solve(s, i+1, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        solve(s, 0, cur);
        return res;
    }
};