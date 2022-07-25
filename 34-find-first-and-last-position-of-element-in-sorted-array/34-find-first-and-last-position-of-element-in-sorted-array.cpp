class Solution {
    int floorBS(vector<int>& nums, int target){
        int low=0, high=nums.size()-1;
        int res=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                res=mid;
                high=mid-1;
            }else if(nums[mid] < target)
                low=mid+1;
            else
                high=mid-1;
        }
        return res;
    }
    int ceilBS(vector<int>& nums, int target){
        int low=0, high=nums.size()-1;
        int res=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                res=mid;
                low=mid+1;
            }else if(nums[mid] < target)
                low=mid+1;
            else
                high=mid-1;
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {floorBS(nums,target), ceilBS(nums, target)};
    }
};