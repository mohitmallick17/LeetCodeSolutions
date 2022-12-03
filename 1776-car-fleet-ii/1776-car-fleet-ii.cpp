class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n=cars.size();
        stack<int> stk;
        vector<double> res(n, -1.0);
        
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && cars[stk.top()][1] >= cars[i][1])
                stk.pop();
            while(!stk.empty()){
                double t = (double)(cars[stk.top()][0] - cars[i][0])/(cars[i][1] - cars[stk.top()][1]);
                if(res[stk.top()]==-1 or res[stk.top()] >= t){
                    res[i] = t;
                    break;
                }
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};