class Solution {
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    }
    int LIS(vector<vector<int>>& v){
        vector<int> cur;
        cur.push_back(v[0][1]);
        
        for(int i=1;i<v.size();i++){
            if(cur.back() < v[i][1]){
                cur.push_back(v[i][1]);
            }
            else{
                int index = lower_bound(cur.begin(), cur.end(), v[i][1]) - cur.begin();
                cur[index] = v[i][1];
            }
        }
        return cur.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        // for(auto x:envelopes)
        //     cout << x[1] << ' ';
        // cout << '\n';
        return LIS(envelopes);
    }
};