class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;
        
        for(int i=0;i<apples.size();i++){
            if(apples[i] > 0)
                pq.push({i+days[i], apples[i]});
            
            while(!pq.empty() and pq.top().first <= i)pq.pop(); // remove rotten apple
            
            if(pq.size()){
                ans++;
                auto x = pq.top();
                pq.pop();
                x.second--;
                if(x.second > 0)
                    pq.push(x);
            }
        }
        int day = days.size();
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            if(x.first > day){
                int cnt = min(x.first-day, x.second);
                ans += cnt;
                day = min(day+cnt, x.first);
            }
        }
        return ans;
    }
};
// [2,1,1,4,5]
// [10,10,6,4,2]