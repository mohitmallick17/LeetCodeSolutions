class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        for(int i=1;i<s.size();i++){
            if(s[i] > s[i-1]){
                // Find largest digit from end;
                int j=s.size()-1;
                int mx=j;
                while(j >= i){
                    if(s[j] > s[mx])mx=j;
                    j--;
                }
                // find first no smaller than MX
                for(j=0;j<i;j++){
                    if(s[j] < s[mx]){
                        swap(s[j], s[mx]);
                        break;
                    }
                }
                break;
            }
        }
        return stoi(s);
    }
};