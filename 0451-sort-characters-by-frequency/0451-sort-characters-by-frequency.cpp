class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> v(128);
        for(int i=0;i<128;i++)
            v[i] = {0,i};
        for(char &c:s)
            v[c].first++;
        sort(v.rbegin(), v.rend());
        s.clear();
        for(auto &[f, c]:v){
            if(f > 0){
                s += string(f,c);
                // cout << f << ' ' << ('a' + c) << '\n';
            }
        }
        return s;
    }
};