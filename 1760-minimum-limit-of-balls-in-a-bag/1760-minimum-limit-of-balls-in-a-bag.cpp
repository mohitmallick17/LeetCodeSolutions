class Solution {
    bool isPossible(vector<int>& nums, int MAX, int maxOp){
        int op=0;
        for(int &x:nums){
            if(x > MAX)
                op += ceil(x/(1.00*MAX))-1;
            if(op > maxOp)return false;
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        cout << isPossible(nums, 3, maxOperations);
        int low=1, high=*max_element(nums.begin(), nums.end());
        
        int ans = high+1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(nums, mid, maxOperations)){
                ans=mid;
                high=mid-1;
            }else
                low=mid+1;
        }
        return ans;
    }
};