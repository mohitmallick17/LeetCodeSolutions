class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> doswap(n), noswap(n);
        noswap[0]=0;
        doswap[0]=1;
        
        for(int i=1;i<n;i++){
            doswap[i]=n, noswap[i]=n;
            if(nums1[i] > nums1[i-1] and nums2[i] > nums2[i-1]){
                noswap[i]=noswap[i-1];
                doswap[i]=doswap[i-1]+1;
            }
            if(nums1[i] > nums2[i-1] and nums2[i] > nums1[i-1]){
                doswap[i] = min(doswap[i], noswap[i-1]+1);
                noswap[i] = min(noswap[i], doswap[i-1]);
            }
        }
        return min(doswap[n-1], noswap[n-1]);
    }
};