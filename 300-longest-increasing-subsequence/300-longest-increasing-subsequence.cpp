class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int size=0;
        
        for(int& num:nums){
            int low=0, high=size;
            while(low<high){
                int mid=low+(high-low)/2;
                if(res[mid] < num)
                    low=mid+1;
                else
                    high=mid;
            }
            res[low]=num;
            if(low==size)size++;
        }
        return size;
    }
};