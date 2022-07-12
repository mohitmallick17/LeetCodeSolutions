class Solution {
    int binarySearchLB(vector<int>& v, int key){
        int low=0, high=v.size()-1;
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(v[mid] >= key){
                ans = mid;
                high=mid-1;
            }else
                low=mid+1;
        }
        return ans;        
    }
    vector<int> LIS(vector<int>& a){
        int n=a.size();
        vector<int> v(n, INT_MAX);
        vector<int> len(n);
        for(int i=0;i<n;i++){
            int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[idx] = a[i];
            len[i] = idx+1;
        }
        return len;
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> left = LIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> right = LIS(nums);
        reverse(right.begin(), right.end());
        
        int n=nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(left[i] > 1 and right[i] > 1)ans=max(ans, left[i]+right[i]-1);
        }
        return n-ans;
    }
};