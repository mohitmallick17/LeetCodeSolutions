class Solution {
    // int solve(int idx, vector<int>& nums){
    //     long long Sum = 0;
    //     for(int &x:nums){
    //         Sum += x-nums[idx];
    //     }
    // }
public:
//     int minMoves2(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n=nums.size();
        
//         if(n&1){
//             return solve(n/2, nums);  
//         }else{
//             return min(solve(n/2 -1, nums), solve(n/2, nums));
//         }
//     }
        int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); //Fixing ths median element
        int median = nums[n/2];
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;
    }

};