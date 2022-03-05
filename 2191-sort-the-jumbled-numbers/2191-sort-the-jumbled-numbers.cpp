
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            string a = to_string(nums[i]);
            string b;
            for(char &c:a)
                b += '0' + mapping[c-'0'];
            v[i] = {stoi(b), i};
        }
        sort(v.begin(), v.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i] = nums[v[i][1]];
        
        return ans;
    }
};