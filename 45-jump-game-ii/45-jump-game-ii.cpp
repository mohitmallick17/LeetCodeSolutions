class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int n=nums.size();
        if(n==1)return 0;
        int l=0,r=0;
        while(r < n-1){
            int nxt = 0;
            for(int i=l;i<=r;i++){
                nxt = max(nxt, i + nums[i]);
            }
            l=r+1;
            r=nxt;
            count++;
        }
        return count;
    }
};