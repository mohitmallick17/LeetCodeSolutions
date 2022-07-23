class Solution {
    void merge(vector<int>& cnt, vector<pair<int, int>>& tmp, vector<pair<int, int>> &nums, int s1, int s2, int end){
        int i=s1, j=s2, k=s1;
        
        while(i < s2 and j<=end){
            if(nums[i].first > nums[j].first){
                cnt[nums[i].second] += end-j+1;
                tmp[k++]=nums[i++];
            }else{
                tmp[k++]=nums[j++];
            }
        }
        while(i<s2)
            tmp[k++]=nums[i++];
        while(j<=end)
            tmp[k++]=nums[j++];
        for(int m=s1;m<=end;m++)nums[m]=tmp[m];
    }
    void mergeSort(vector<int>& cnt, vector<pair<int, int>>& tmp, vector<pair<int, int>> &num_idx, int lo, int hi){
        if(lo < hi){
            int mid = lo + (hi-lo)/2;
            mergeSort(cnt, tmp, num_idx, lo, mid);
            mergeSort(cnt, tmp, num_idx, mid+1, hi);
            
            merge(cnt, tmp, num_idx, lo, mid+1, hi);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> cnt(n);
        vector<pair<int, int>> num_idx(n), tmp(n);
        for(int i=0;i<n;i++){
            num_idx[i] = {nums[i], i};
        }
        mergeSort(cnt, tmp, num_idx, 0, n-1);
        
        return cnt;
    }
};