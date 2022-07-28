class Solution {
public:
    int minInsertions(string s) {
        int cost = 0;
        int n=s.size();
        stack<int> stk;
        for(int i=0;i<n;i++){
            if(s[i] == '(')
                stk.push(i);
            else{
                if(stk.empty()){
                    cost++; // no prev (                    
                }else{
                    stk.pop();
                }
                if(i==n-1 or s[i+1] != ')')cost++;
                else i++;
            }
        }
        cost += 2*(stk.size()); // 2 closings for each open (
        return cost;
    }
};