class Solution {
public:
    int minDeletions(string s) {
        int cnt[26] = {}, res = 0;
        for (char ch : s)
            ++cnt[ch - 'a'];
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(cnt[i]>0)
                pq.push(cnt[i]);
        }
        unordered_set<int> vis;
        
        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            if(vis.find(val) != vis.end()){
                res++;
                if(val-1 > 0)
                    pq.push(val-1);
            }else
                vis.insert(val);
        }
        return res;
    }
};