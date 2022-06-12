class Solution {
    int res = INT_MAX;
    void solve(int i,const vector<int>& v, vector<int>& x){
        if(i==v.size()){
            int mx = *max_element(x.begin(), x.end());
            res = min(res, mx);
            return;
        }
        
        for(int c=0;c<x.size();c++){
            x[c] += v[i];
            solve(i+1, v, x);
            x[c] -= v[i];
        }
        
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> x(k, 0);
        solve(0, cookies, x);
        return res;
    }
};