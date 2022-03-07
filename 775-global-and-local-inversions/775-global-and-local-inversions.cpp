class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        // Always, locals <= globals
        // every local is also a global
        // if we find 1 global which is not zero -> return false
        // i.e i < j where j >= i+2 and j < n. for all i
        
        int maxVal = -1;
        for(int i=0;i<(int)nums.size()-2;i++){
            maxVal = max(maxVal, nums[i]); // maximize the value
            // if any number at j (j>=i+2) is less than any previous i, it's a global (with gap >= 2)
            if(maxVal > nums[i+2])return false;
        }
        return true;
    }
};