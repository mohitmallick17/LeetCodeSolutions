class Solution {
    vector<vector<int>> res;
    void solve(int idx, vector<int>& candidates, vector<int>& cur, int target){
        if(idx==candidates.size() or target <= 0){
            if(target==0)res.push_back(cur);
            return;
        }
        
        for(int i=idx;i<candidates.size();i++){
            if(i > idx and candidates[i]==candidates[i-1])continue;
            cur.push_back(candidates[i]);
            solve(i+1, candidates, cur, target-candidates[i]);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        solve(0, candidates, cur, target);
        return res;
    }
};