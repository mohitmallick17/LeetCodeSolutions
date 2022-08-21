class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10, 0);
        
        for(char &c:num)cnt[c-'0']++;
        
        string f, r;
        
        for(int i=9;i>=0;i--){
            int x = cnt[i]/2;
            f += string(x, '0'+i);
            cnt[i] -= 2*x;
        }
        if(f.front()=='0')f.clear();
        bool isOdd=false;
        char mid;
        for(int i=9;i>=0;i--){
            if(cnt[i] > 0){
                isOdd=true;
                mid='0'+i;
                break;
            }
        }
        r=f;
        reverse(r.begin(), r.end());
        string ans = isOdd ? f + mid + r : f+r;
        if(ans.empty())return "0";
        return ans;
    }
};