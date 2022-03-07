class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> nums(m+1);
        for(int i=0;i<=m;i++){
            nums[i]=i;
        }
        vector<int> res;
        for(int q:queries){
            auto it = find(nums.begin(), nums.end(), q);
            res.push_back(it - nums.begin() - 1);
            nums.erase(it);
            nums.insert(nums.begin()+1, q);
        }
        return res;
    }
};