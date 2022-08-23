class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;
        
        for(int i=0;i<apples.size();i++){
            if(apples[i] > 0)
                pq.push({i+days[i], apples[i]});
            
            while(!pq.empty() and pq.top().first <= i)pq.pop(); // remove rotten apple
            
            // increment only by 1, to accomodate future apples (which might have lesser expiry)
            // therefore we eat apple only on i'th day until we have seen all the apples & their expiry
            if(pq.size()){
                ans++;
                auto x = pq.top();
                pq.pop();
                x.second--;
                if(x.second > 0) // if still have apples, push it
                    pq.push(x);
            }
        }
        // after n days, we won't add more apples, but finish existing ones.
        // so be greedy and finish the ones closest to expiry
        int day = days.size();
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            if(x.first > day){ // apples should not be expired
                int cnt = min(x.first-day, x.second); // count total apples we can take 
                //  cnt = min(apples we have, days between expiry date-today's date)
                ans += cnt;
                day += cnt;
            }
        }
        return ans;
    }
};