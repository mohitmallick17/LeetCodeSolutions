class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> vp;
        for(int i=0;i<speed.size();i++)
            vp.push_back({position[i], speed[i]});
        sort(vp.begin(), vp.end());
        
        int cnt = 1;
        double prev = ((double)(target - vp.back().first))/vp.back().second;
        
        for(int i=vp.size()-2;i>=0;i--){
            int d = target - vp[i].first;
            double t = (double)d / vp[i].second;
            // cout << t << ' ' << prev << ' ';
            if(t > prev){
                prev = t;
                cnt++;
                // cout << "trigger";
            }
            // cout << '\n';
        }
        return cnt;
    }
};

/*
target = 12

T = D/V

2M / 2M/S = 1 S
4 / 4 = 1 S

7 / 1 = 7
9 / 3 = 7

12 / 1 = 12

0 3 5 8 10
1 3 1 4 2

*/