class Solution {
public:
    string largestPalindromic(string num) {
        if(num.size()==1)return num;
        
        vector<int> mp(10, 0);
        
        for(char &c:num)mp[c-'0']++;
        
        string f, r;
        
        for(int i=9;i>=0;i--){
            cout << i << ' ' << mp[i] << '\n';
            int x = mp[i]/2;
            f += string(x, '0'+i);
            mp[i] -= 2*x;
        }
        if(f.front()=='0')f.clear();
        for(int i=9;i>=0;i--){
            if(mp[i] > 0){
                r = f;
                reverse(r.begin(), r.end());
                return f  + string(1, i+'0') + r;
            }
        }
        r=f;
        reverse(r.begin(), r.end());
        string ans = f+r;
        if(ans.empty())return "0";
        return ans;
    }
};