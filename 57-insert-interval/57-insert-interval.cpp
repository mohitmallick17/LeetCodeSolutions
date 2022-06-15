class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0, n=intervals.size();
        
        // add all intervals smaller than newInterval.start
        while(i<n and intervals[i][1] < newInterval[0])
            res.push_back(intervals[i++]);
        
        // merge overlapping intervals
        while(i<n and intervals[i][0] <= newInterval[1]){
            newInterval[0]=min(newInterval[0], intervals[i][0]);
            newInterval[1]=max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        res.push_back(newInterval);
        // add all intervals smaller than newInterval.start
        while(i<n)
            res.push_back(intervals[i++]);
        
        return res;
    }
};