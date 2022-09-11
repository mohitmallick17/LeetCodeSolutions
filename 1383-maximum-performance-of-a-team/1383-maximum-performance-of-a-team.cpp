class Solution {
    long long mod=1e9 + 7;
    pair<long long, long long> solve(int idx, int k, vector<int>& speed, vector<int>& efficiency){
        if(idx==speed.size())
            return {0, LONG_MAX};
        
        long long inc=0, exc=0;
        pair<long long, long long> ret;
        if(k > 0){
            auto x = solve(idx+1, k-1, speed, efficiency);
            // take this engineer
            long long s = (speed[idx] + x.first)%mod;
            long long e = min((long long)efficiency[idx], x.second) % mod;
            inc = s * e;
            ret = {s, e};
        }
        auto y = solve(idx+1, k, speed, efficiency);
        // skip the engineer
        exc = y.first * y.second;
        return (inc > exc) ? ret:y;
    }
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // auto ans = solve(0,k,speed,efficiency);    
        // return ans.first * ans.second;
        
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++)v[i] = {efficiency[i], speed[i]};
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        long long ans = 0;
        
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0;i<n;i++){
            int e = v[i].first;
            if(pq.size() == k){
                sum -= pq.top();
                pq.pop();
            }
            sum += v[i].second;
            pq.push(v[i].second);
            long long s = sum;
            // cout << e << ' ' << v[i].second << '\n';
            ans = max(ans, s*(long long)e);
        }
        return ans%mod;
    }
};