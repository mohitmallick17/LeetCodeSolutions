class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for(auto &x:reservedSeats){
            int r=x[0], c=x[1];
            if(!mp.count(r))
                mp[r]=1<<c;
            else
                mp[r] = (mp[r]) | (1<<c);
        }
        int res = 0;
        
        for(auto &[k, v]:mp){
            // key k = row, val v=reserved seats. ex 1110001100
            int seat_cnt=0;
            if((v & 60) == 0)seat_cnt++;
            if((v & 960) == 0)seat_cnt++;
            if((v & 240)==0 and seat_cnt==0)seat_cnt=1;
            
            res += seat_cnt;
        }
        return res + 2*(n-mp.size());
    }
};