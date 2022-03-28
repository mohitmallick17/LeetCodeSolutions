class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(nums[mid]==target)
                return true;
            else if(nums[low]==nums[mid] and nums[mid]==nums[high]) // low mid high point to a same value
                low++, high--;  // we can't tell where the result lies, so reduce the range by one from both ends
            else if(nums[mid] <= nums[high]){ // right side is sorted
                if(target > nums[mid] and target <= nums[high])    // target lies in the sorted size
                    low=mid+1;
                else                       // target lies in the unsorted size
                    high=mid-1;
            }else{  // left side is sorted
                if(target>=nums[low] and target < nums[mid])    // target lies in the sorted size
                    high=mid-1;
                else                     // target lies in the unsorted size
                    low=mid+1;
            }
        }
        return false;
    }
};