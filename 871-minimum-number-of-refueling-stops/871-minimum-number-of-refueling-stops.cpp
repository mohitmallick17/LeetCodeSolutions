class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int pq_i=0;
        int count=0, maxD=startFuel;
        
        while(maxD < target){
            while(pq_i < stations.size() and maxD >= stations[pq_i][0]){
                pq.push(stations[pq_i][1]);pq_i++;
            }
            if(pq.size()){
                maxD += pq.top();
                pq.pop();
                count++;
            }else
                return -1;
        }
        return count;
    }
};