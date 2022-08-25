class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        sort(points.begin(), points.end());
        vector<int> res;
        
        for(auto &q:queries){
            int cnt = 0;
            int x=q[0], y=q[1], r=q[2];
            int rr = r*r;
            vector<int> key{x-r, 0};
            // target is all points from x-r to x+r (within radius, for x)
            auto it = lower_bound(points.begin(), points.end(), key);
            for(;it!=points.end() and (*it)[0] <= x+r;++it)
                cnt += (pow((x-(*it)[0]),2) + pow((y-(*it)[1]),2)) <= rr;
            res.push_back(cnt);
        }
        return res;
    }
};