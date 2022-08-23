struct item{
    int ST;
    int PT;
    int idx;
    
    item(int s, int p, int i) : ST(s), PT(p), idx(i) {}
    
    bool operator<(const item& i) const {
        if(this->PT != i.PT)
            return this->PT > i.PT;
        return this->idx > i.idx;
    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<item> pq;
        vector<item> v;
        for(int i=0;i<tasks.size();i++)
            v.push_back(item(tasks[i][0], tasks[i][1], i));
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.ST < b.ST;
        });
        
        vector<int> res;
        
        long long t=v.front().ST;
        int i=0, n=v.size();
        
        while(!pq.empty() or i<n){
            while(i<n and v[i].ST<=t){
                pq.push(v[i]);
                i++;
            }
            if(pq.size()){
                auto x = pq.top();
                pq.pop();
                t += x.PT;
                res.push_back(x.idx);
            }else
                t = v[i].ST;
        }
        return res;
    }
};