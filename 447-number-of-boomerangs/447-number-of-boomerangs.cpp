class Solution {
    int getDist(vector<int>& a, vector<int>& b){
        int x = a[0]-b[0];
        int y = a[1]-b[1];
        
        int d = (x*x + y*y); // dist b/w 2 points
        
        return d;
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        int res=0;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i==j)continue;
                int dist = getDist(points[i], points[j]);
                mp[dist]++;
            }
            for(auto &[k, v]:mp){
                res += v*(v-1);
            }
            mp.clear();
        }
        return res;
    }
};