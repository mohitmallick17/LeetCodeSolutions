class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n=arr.size();
        for(int &a:arr)mp[a]++;
        priority_queue<int> pq;
        for(auto &x:mp)pq.push(x.second);
        
        int i=0;
        int cnt=0;
        while(!pq.empty() and i < (n+1)/2){
            i += pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};