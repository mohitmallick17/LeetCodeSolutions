class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dist(n+1, 0);
        
        for(int i=0;i<=n;i++){
            if(ranges[i]==0)continue;
            int left = max(0, i-ranges[i]);
            dist[left] = max(dist[left], i+ranges[i]);
        }
        
        int l=0, r=0;
        int count = 0;
        
        while(r < n){
            int nxt_r = 0;
            for(int i=l;i<=r;i++){
                nxt_r = max(nxt_r, dist[i]);
            }
            if(r == nxt_r)return -1;
            l = r+1;
            r = nxt_r;
            count++;
        }
        return count;
    }
};