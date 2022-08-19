class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> FM, HM;
        for(auto &x:nums)FM[x]++;
        
        for(auto &x:nums){
            if(FM[x]==0)continue; // num already processed
            // there is space for this no
            if(HM[x] > 0){
                HM[x]--; // put it in space
                FM[x]--; // reduce freq
                HM[x+1]++; // and create space for x+1th no
            }else if(FM[x] > 0 and FM[x+1] > 0 and FM[x+2] > 0){
                FM[x]--, FM[x+1]--, FM[x+2]--;
                HM[x+3]++;
            }
            else
                return false;
        }
        return true;
    }
};