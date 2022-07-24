class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int prev_a = 0, prev_b = 0;
        
        for(int i=1;i<=n;i++){
            int cur_a = prev_a + (s[i-1]=='b');
            int cur_b = min((prev_b + (s[i-1]=='a')) , (prev_a + (s[i-1]=='a')));
            prev_a=cur_a, prev_b=cur_b;
        }
        // for(int i=1;i<=n;i++)cout << a[i] << ' ';
        // cout << '\n';
        // for(int i=1;i<=n;i++)cout << b[i] << ' ';
        // cout << '\n';
        return min(prev_a, prev_b);
    }
};