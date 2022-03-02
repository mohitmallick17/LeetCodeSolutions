class Solution {
    long long solve(vector<int>& price, vector<vector<int>>& special, vector<int> needs){
        bool done=true;
        for(int i=0;i<needs.size();i++){
            if(needs[i]>0){
                done=false;
                break;
            }
        }
        if(done)return 0;
        
        long long ans = 0;
        
        for(int i=0;i<needs.size();i++){
            ans += 1LL * price[i] * needs[i];
        }
        for(auto &v:special){
            bool check = true;
            for(int i=0;i<needs.size();++i){
                if(v[i] > needs[i]){
                    check=false;
                    break;
                }
            }
            if(check){
                vector<int> nneds = needs;
                
                for(int i=0;i<needs.size();++i){
                    nneds[i] -= v[i];
                }
                ans = min(ans, 1LL*v.back() + solve(price, special, nneds)); 
            }
        }
        return ans;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price, special, needs);
    }
};