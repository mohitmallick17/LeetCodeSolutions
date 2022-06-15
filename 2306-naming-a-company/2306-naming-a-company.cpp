class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> hash(26);
        for(auto &s:ideas){
            hash[s[0]-'a'].insert(s.substr(1));
        }
        long long ans = 0;
        
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                int common_cnt=0;
                for(auto &x:hash[i]){
                    common_cnt += hash[j].count(x);
                }
                // A: x, B:y, common: z. Total pairs permutation: (x-z)*(y-z) * 2 (we can write pair a,b as b,a)
                ans += 2 * (hash[i].size() - common_cnt) * (hash[j].size() - common_cnt);
            }
        }
        return ans;
    }
};