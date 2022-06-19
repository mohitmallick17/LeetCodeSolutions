class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> stk = {INT_MAX};
        int res = 0;
        
        for(const int &a:arr){
            while(stk.back() <= a){
                int mid = stk.back();
                stk.pop_back();
                int left = stk.back();
                int right = a;
                res += mid * min(left, right);
            }
            stk.push_back(a);
        }
        for(int i=2;i<stk.size();i++)
            res += stk[i-1]*stk[i];
        return res;
    }
};