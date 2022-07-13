class Solution {
    int getSteps(int curDigit, string& s){
        int cost = 0;
        for(char &c:s){
            if(c-'0' != curDigit)cost++;
            curDigit = !curDigit; 
        }
        // why cost/2? bcoz if 111000 -> 101010, our cost = 2 cuz we calculate incorrect pos twice
        return cost/2;
    }
public:
    int minSwaps(string s) {
        int oc=0, zc=0;
        for(char &c:s){
            if(c=='0')zc++;
            else oc++;
        }
        if(abs(oc-zc) > 1)return -1;
        if(oc == zc){
            // ones == zeros
            // we can start with 1 or 0
            // ans = min of both
            int start_with_zero = getSteps(0, s);
            int start_with_one = getSteps(1, s);
            return min(start_with_zero, start_with_one);
        }
        return (oc > zc) ? getSteps(1, s) : getSteps(0, s);
    }
};