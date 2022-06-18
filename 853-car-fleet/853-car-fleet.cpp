class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++){
            v[i] = {position[i], speed[i]};
        }
        sort(v.begin(), v.end());
        double max_time=0.0;
        int res=0;
        
        for(int i=n-1;i>=0;i--){
            double cur_time=(target-v[i].first)/(double)v[i].second;
            if(cur_time > max_time){
                max_time=cur_time;
                res++;
            }
        }
        return res;
    }
};