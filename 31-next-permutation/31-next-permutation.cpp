class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        for(;i>=0;i--){
            if(nums[i] < nums[i+1])
                break;
        }
        // all nos are descending: sort and return since no next permutation possible
        if(i==-1){
            sort(nums.begin(), nums.end());
            return;
        }
        // so we found item nums[i] which is smaller than it's next element
        // just swap it with the first greater no from rightmost side.
        // why? cause all elements from i+1 to n-1 are sorted in decreasing order
        int j;
        for(j=n-1;j>i;j--){
            if(nums[i] < nums[j])
                break;
        }
        swap(nums[i], nums[j]);
        sort(nums.begin()+i+1, nums.end());
    }
};