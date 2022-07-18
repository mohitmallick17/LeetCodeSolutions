class Solution {
    vector<vector<int>> ans;
    void solve(int i, int n, int cur_k, int k, vector<int> &cur){
        if(cur_k==0){
            ans.push_back(cur);
            return;
        }
        
        for(int num=i;num<=n;num++){
            cur.push_back(num);
            solve(num+1, n, cur_k-1, k, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        solve(1, n, k, k, cur);
        return ans;
    }
};