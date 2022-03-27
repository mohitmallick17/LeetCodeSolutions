struct cmp{
    bool operator()(pair<int, int> const &a, pair<int, int> const &b) {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }    
};
class Solution {
    int getOneCnt(vector<int> &v){
        int lo=0, hi=v.size()-1;
        
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(v[mid]==1){
                ans=mid;
                lo=mid+1;
            }else
                hi=mid-1;
        }
        return ans;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        
        for(int i=0;i<mat.size();i++){
            pq.push({getOneCnt(mat[i]), i});
            if(pq.size() > k)pq.pop();
        }
        vector<int> ans(k);
        for(int i=k-1;i>=0;i--){
            ans[i]=pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};