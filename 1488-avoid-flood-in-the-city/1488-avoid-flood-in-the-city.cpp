class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> prevRain;
        set<int> dry;
        
        vector<int> res(rains.size(), -1);
        for(int i=0;i<rains.size();i++){
            int lake = rains[i];
            if(lake==0){
                dry.insert(i);
                res[i]=1;
            }
            else if(prevRain.find(lake) == prevRain.end()){
                prevRain[lake]=i; // it rained on ith day
            }else{
                // it rained previously
                int prev = prevRain[lake];
                auto it = dry.upper_bound(prev);
                if(it==dry.end())return {}; // impossible since no dry day between prev rain day & today
                res[*it]=lake; // dry this lake
                dry.erase(it);
                prevRain[lake]=i;
            }
        }
        return res;
    }
};