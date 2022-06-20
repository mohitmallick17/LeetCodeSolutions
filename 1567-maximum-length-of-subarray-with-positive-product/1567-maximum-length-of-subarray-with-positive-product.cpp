class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos=0, neg=0;
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                pos=neg=0;
            }else if(nums[i] > 0){
                pos++; // positive * positive = positive
                neg = (neg==0) ? 0 : neg+1; // if no num is negative so far, u can't form it. else increase len 
                // because negative * positive = negative 
            }else{
                int tmp = pos;
                pos = (neg==0) ? 0:neg+1; // if no negative so far, we can't form positive no
                // else we can multiply negative*negative=positive
                neg = tmp+1; // positive so far * neg = neg
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};