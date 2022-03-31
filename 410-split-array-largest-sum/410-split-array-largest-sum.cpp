class Solution {
    bool canAccomodate(int maxSum, vector<int>& nums, int m){
        int n=1;
        int sum=0;
        for(int num:nums){
            if(sum + num > maxSum){
                sum = num;
                n++;
            }else
                sum += num;
            if(n > m)return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int low = INT_MIN, high=0;
        for(int &x:nums){
            high += x;
            low = max(low, x);
        }
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canAccomodate(mid, nums, m))
                high=mid-1, ans=mid;
            else
                low=mid+1;
        }
        return ans;
    }
};