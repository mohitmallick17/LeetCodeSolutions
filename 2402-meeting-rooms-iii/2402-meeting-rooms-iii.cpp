class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> vacant; // room_id
        // pair: end_time : room_id
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> in_use;
        
        vector<int> freq(n, 0);
        
        for(int i=0;i<n;i++)
            vacant.push(i);
        
        for(auto &x:meetings){
            int s=x[0], e=x[1];
            
            while(!in_use.empty() and in_use.top().first <= s){
                int room = in_use.top().second;
                in_use.pop();
                vacant.push(room);
            }
            
            if(!vacant.empty()){
                int room_id = vacant.top();
                vacant.pop();
                freq[room_id]++;
                in_use.push({e, room_id});
            }else{
                // need to wait
                auto p = in_use.top();
                in_use.pop();
                long long meetingEndTime = p.first;
                int room_id = p.second;
                freq[room_id]++;
                meetingEndTime += e-s;
                in_use.push({meetingEndTime, room_id});
            }
        }
        int ans=freq[0], ans_i=0;
        for(int i=1;i<n;i++){
            if(ans < freq[i]){
                ans = freq[i];
                ans_i=i;
            }
        }
        return ans_i;
    }
};