class Solution {
public:
    int partitionString(string s) {
        int cnt=1;
        int used = 0;
        for(int i=0;i<s.size();i++){
            int ch = s[i] - 'a';
            if(((used >> ch) & 1)){
                // char is already used
                cnt++;
                used=(1<<ch);
            }else{
                used |= (1<<ch);
            }
        }
        return cnt;
    }
};