class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        
        for(auto &a:asteroids){
            bool destroyed=false;
            while(!res.empty() and res.back() > 0 and a < 0){
                if(res.back() == -a){
                    res.pop_back();
                    destroyed=true;
                    break;
                }else if(res.back() < -a){
                    res.pop_back();
                }else{
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed)
                res.push_back(a);
        }
        return res;
    }
    
};