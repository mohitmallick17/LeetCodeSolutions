class Solution {
    int binarySearch(vector<int>& v, int key){
        // find ceil
        int res = -1;
        int low=0, high=v.size()-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(v[mid] >= key){
                res = mid;
                high=mid-1;
            }else
                low=mid+1;
        }
        return res;
    }
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> v;
        
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(v.empty() or v.back() < num)
                v.push_back(num);
            else{
                int index = binarySearch(v, num);
                v[index] = num; 
            }
            if(v.size() == 3)return true;
        }
        return false;
    }
};