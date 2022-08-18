class Solution {
public:
    string getHint(string secret, string guess) {
        int b=0, c=0;
        vector<int> cnt(10, 0);
        
        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i])b++;
            else{
                if(cnt[secret[i]-'0'] < 0)c++;
                if(cnt[guess[i]-'0'] > 0)c++;
                cnt[secret[i]-'0']++;
                cnt[guess[i]-'0']--;
            }
        }
        return to_string(b) + "A" + to_string(c)  + "B";
    }
};