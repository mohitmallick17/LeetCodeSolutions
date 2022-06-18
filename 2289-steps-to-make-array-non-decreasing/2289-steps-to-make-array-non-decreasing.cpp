class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int, int>> stk;
        int res=0;
        for(int i=nums.size()-1;i>=0;i--){
            int step_cnt=0; // steps needed to del all decreasing nos after i
            while(!stk.empty() and stk.top().first < nums[i]){
                step_cnt = max(step_cnt+1, stk.top().second);
                stk.pop();
            }
            stk.push({nums[i], step_cnt});
            res = max(res, step_cnt);
        }
        return res;
    }
};