class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<pair<int, int>> v(n);
        for(int i=0;i<costs.size();i++){
            v[i] = {costs[i][1]-costs[i][0], i};
        }
        sort(v.begin(), v.end()); // sort by difference in increasing order
        int res = 0;
        
        for(int i=0;i<n;i++){
            if(i < n/2){
                // choose B
                // difference of A and B is small, pick B 
                res += costs[v[i].second][1];
            }else{
                // choose A
                // difference of A and B is large, pick A '.' B > A
                res += costs[v[i].second][0];
            }
        }
        return res;
    }
};