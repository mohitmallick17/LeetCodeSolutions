class Solution {
    map<int, int, greater<>> mp;
    
    bool hasEnoughBalls(int M, int orders){
        for(auto &[n, cnt]:mp){
            if(n <= M)break;
            orders -= cnt*(n-M);
            if(orders<=0)return true;
        }
        return false;
    }
public:
    int maxProfit(vector<int>& a, int orders) {
        long long low=0, high=a[0];
        for(int &x:a){
            high=max(high, (long long)x);
            mp[x]++;
        }
        
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(hasEnoughBalls(mid, orders))low=mid+1;
            else high=mid-1;
        }
        // low = smallest invalid index, high=largest valid index
        // we are looking for smallest invalid idx. invalid = we have less balls than order
        
        long long ans = 0, mod=1e9 + 7;
        for(auto &[n, cnt]:mp){
            if(n <= low)break;
            orders -= cnt*(n-low);
            // Sum of AP = N * (a_1 + a_n)/2
            ans = (ans + ((n-low)*(low+1 + n))/2 % mod * cnt % mod)%mod;
        }
        if(orders>0)ans = (ans + low*orders%mod)%mod;
        
        return ans;
    }
};