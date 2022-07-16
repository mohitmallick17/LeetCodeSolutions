class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> nums(n, 1);
        
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1])
                nums[i]=nums[i-1]+1;
        }
        int ans=0;
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i])
                nums[i-1]=max(nums[i-1], nums[i]+1);
        }
        for(int i=0;i<n;i++)ans+=nums[i];
        return ans;
    }
};