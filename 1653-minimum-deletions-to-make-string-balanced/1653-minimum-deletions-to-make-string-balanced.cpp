class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> a(n+1), b(n+1);
        
        for(int i=1;i<=n;i++){
            a[i] = a[i-1] + (s[i-1]=='b');
            b[i] = min((b[i-1] + (s[i-1]=='a')) , (a[i-1] + (s[i-1]=='a')));
        }
        // for(int i=1;i<=n;i++)cout << a[i] << ' ';
        // cout << '\n';
        // for(int i=1;i<=n;i++)cout << b[i] << ' ';
        // cout << '\n';
        return min(a[n], b[n]);
    }
};