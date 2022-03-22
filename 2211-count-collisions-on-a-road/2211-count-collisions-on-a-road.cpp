class Solution {
public:
    int countCollisions(string directions) {
        vector<pair<char, int>> v;
        int n=directions.size();
        for(int i=0;i<n;i++){
            int cnt=1;
            while(i+1<n and directions[i]==directions[i+1])
                i++, cnt++;
            v.push_back({directions[i], cnt});
        }
        int cnt = 0;
        for(int i=0;i<v.size()-1;i++){
            if(v[i].first == 'R' and v[i+1].first == 'L')
                cnt += v[i].second + v[i+1].second;
            else if(v[i].first == 'R' and v[i+1].first == 'S')
                cnt += v[i].second;
            else if(v[i].first == 'S' and v[i+1].first == 'L')
                cnt += v[i+1].second;
        }
        return cnt;
    }
};