class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int prev_doswap, prev_noswap;
        prev_noswap=0;
        prev_doswap=1;
        
        for(int i=1;i<n;i++){
            int cur_doswap, cur_noswap;
            cur_doswap=n, cur_noswap=n;
            
            if(nums1[i] > nums1[i-1] and nums2[i] > nums2[i-1]){
                cur_noswap=prev_noswap;
                cur_doswap=prev_doswap+1;
            }
            if(nums1[i] > nums2[i-1] and nums2[i] > nums1[i-1]){
                cur_doswap = min(cur_doswap, prev_noswap+1);
                cur_noswap = min(cur_noswap, prev_doswap);
            }
            prev_doswap=cur_doswap;
            prev_noswap=cur_noswap;
        }
        return min(prev_doswap, prev_noswap);
    }
};