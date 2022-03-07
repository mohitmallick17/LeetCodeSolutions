class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorv = 0;
        for(int &num:nums)
            xorv ^= num;
        long long n1=0, n2=0;
        long long mask = (xorv & (-xorv));
        // cout << xorv << ' ' << mask << '\n';
        for(int &num:nums){
            if(num & mask)
                n1 ^= num;
            else
                n2 ^= num;
        }
        return {(int)n1, (int)n2};
    }
};