class Solution {
public:
    int findUnsortedSubarray(vector<int>& v1) {
        vector<int> v2=v1;
        sort(v2.begin(), v2.end());
        
        int st=0, en=v1.size()-1;
        
        while(st <= en and v1[st]==v2[st])st++;
        while(en >= st and v1[en]==v2[en])en--;
        
        return en-st+1;
    }
};