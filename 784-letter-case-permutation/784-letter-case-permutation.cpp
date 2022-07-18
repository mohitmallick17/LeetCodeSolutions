class Solution {
    vector<string> res;
    void solve(int idx, string &s){
        if(idx==s.size()){
            res.push_back(s);
            return;
        }
        // if lower, try making it upper
        if(s[idx] >= 'a' and s[idx] <= 'z'){
            s[idx] -= 32;
            solve(idx+1, s);
            s[idx] += 32;
        }
        // if upper try making it upper
        if(s[idx] >= 'A' and s[idx] <= 'Z'){
            s[idx] += 32;
            solve(idx+1, s);
            s[idx] -= 32;            
        }
        // if lower, use lower too, similarly use upper for upper too. + for digits do nothing
        solve(idx+1, s);
    }
public:
    vector<string> letterCasePermutation(string s) {
        solve(0, s);
        return res;
    }
};