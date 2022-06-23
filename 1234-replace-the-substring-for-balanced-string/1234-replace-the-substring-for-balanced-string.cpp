class Solution {
public:
    int balancedString(string str) {
        unordered_map<char, int> mp;
        for(char &c:str)mp[c]++;
        int k=str.size()/4;
        int res = str.size(), n=str.size();
        
        for(int s=0, e=0;e<n;e++){
            mp[str[e]]--;
            
            while(s<n and mp['Q']<=k and mp['W']<=k and mp['E']<=k and mp['R']<=k){
                res = min(res, e-s+1);
                mp[str[s]]++;
                s++;
            }
        }
        return res;
    }
};