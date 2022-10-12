class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int s1=INT_MAX, s2=INT_MAX;
        
        for(const int &num:nums){
            if(num <= s1)s1=num;
            else if(num <= s2)s2=num;
            else return true;
        }
        return false;
    }
};