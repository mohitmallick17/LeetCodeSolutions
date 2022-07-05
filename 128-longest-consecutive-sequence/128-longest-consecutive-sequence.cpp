class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int &n:nums)s.insert(n);
        
        int res=0;
        
        for(int n:nums){
            // smallest no: find len
            if(s.find(n-1) == s.end()){
                int len=0;
                while(s.find(n) != s.end())n++, len++;                
                res = max(res, len);
            }
        }
        return res;
    }
};