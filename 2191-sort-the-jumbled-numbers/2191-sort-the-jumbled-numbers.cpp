
class Solution {
    // bool cmp(vector<int> a, vector<int>b){
    //     // if(a[0]==b[0])
    //     return a[0] < b[0];
    // }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<vector<int>> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            string a = to_string(nums[i]);
            string b;
            for(char &c:a){
                b += '0' + mapping[c-'0'];
            }
            v.push_back({stoi(b), i});
        }
        sort(v.begin(), v.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = nums[v[i][1]];
        }
        return ans;
    }
};