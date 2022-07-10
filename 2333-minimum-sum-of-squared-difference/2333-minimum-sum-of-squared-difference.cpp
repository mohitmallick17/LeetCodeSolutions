class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int> v(n);
        int maxDiff = INT_MIN;
        for(int i=0;i<n;i++){
            v[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, v[i]);
        }
        vector<int> bucket(maxDiff+1, 0);
        for(int &x:v)
            bucket[x]++;
        
        int k=k1+k2;
        
       for(int i=maxDiff;i>0 and k>0;i--){
           int debit = min(k, bucket[i]);
           bucket[i]  -= debit;
           bucket[i-1] += debit;
           k-=debit;
        }
        long long res = 0LL;
        
        for(long long i=1;i<=maxDiff;i++){
            // diff^2 * count of all such diff
            res += (i*i) * bucket[i];
        }
        return res;
    }
};