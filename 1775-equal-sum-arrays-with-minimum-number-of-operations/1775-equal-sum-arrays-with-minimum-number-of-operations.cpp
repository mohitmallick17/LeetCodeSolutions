class Solution {
    int sortIt(vector<int>& v){
        vector<int> cnt(7, 0);
        int sum = 0;
        for(int &x:v){
            cnt[x]++;
            sum += x;
        }
        for(int i=1, index=0;index<v.size();index++){
            while(cnt[i]==0)i++;
            v[index]=i;
            cnt[i]--;
        }
        return sum;
    }
    int solve(int s1, int s2, vector<int>& nums1, vector<int>& nums2){
        // Always, s1 > s2
        int lmin = nums1.size()*1;
        int rmax = nums2.size()*6;
        if(lmin > rmax)return -1;
        
        int steps=0;
        // i-> pointer for nums1, j-> pointer for nums2
        int i=nums1.size()-1, j=0;
        while(i>=0 or j<nums2.size()){
            if(s1 == s2)break;
            int reduce_at_nums1=0, increase_at_nums2=0;
            if(i >= 0 and nums1[i] > 1){
                reduce_at_nums1 = min(nums1[i]-1, s1-s2);
            }
            if(j < nums2.size() and nums2[j] < 6){
                increase_at_nums2 = min(6-nums2[j], s1-s2);
            }
            
            if(reduce_at_nums1 >= increase_at_nums2){
                s1 -= reduce_at_nums1;
                i--;
            }else{
                
                s2 += increase_at_nums2;
                j++;
            }
            steps++;
        }
        return steps;
    }
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1=sortIt(nums1);
        int s2=sortIt(nums2);
        if(s1==s2)
            return 0;
        else if(s1 > s2)
            return solve(s1,s2,nums1, nums2);
        else
            return solve(s2,s1,nums2, nums1);
    }
};