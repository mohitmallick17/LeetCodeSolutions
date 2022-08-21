class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> moves(s.size()+1, 0);
        
        for(auto &x:shifts){
            if(x[2]==0){
                moves[x[0]]--;
                moves[x[1]+1]++;
            }else{
                moves[x[0]]++;
                moves[x[1]+1]--;
            }
        }
        int sum = 0;
        
        for(int i=0;i<s.size();i++){
            int c = s[i] - 'a';
            sum += moves[i];
            c = (((c + sum)%26)+26)%26;
            s[i] = (char)c + 'a';
        }
        return s;
    }
};