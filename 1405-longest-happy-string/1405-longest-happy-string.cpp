class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a)
            pq.push({a, 'a'});
        if(b)
            pq.push({b, 'b'});
        if(c)
            pq.push({c, 'c'});
        string res;
        
        while(!pq.empty()){
            auto mx = pq.top();
            pq.pop();
            int sz=res.size();
            if(sz < 2 or res[sz-1]!=mx.second or res[sz-2]!=mx.second)
                res += mx.second, mx.first--;
            else{
                if(pq.empty())return res;
                auto second_mx = pq.top();
                pq.pop();
                res += second_mx.second;
                second_mx.first--;
                if(second_mx.first > 0)pq.push(second_mx);
            }
            if(mx.first > 0)pq.push(mx);
        }
        return res;
    }
};