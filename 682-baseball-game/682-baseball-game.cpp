class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        for(string &op:ops){
            if(op=="D"){
                stk.push(2 * stk.top());
            }else if(op=="C"){
                stk.pop();
            }else if(op=="+"){
                int prev = stk.top();
                stk.pop();
                int prev2 = stk.top();
                stk.push(prev);
                stk.push(prev+prev2);
            }else{
                stk.push(stoi(op));
            }
        }
        int res=0;
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};