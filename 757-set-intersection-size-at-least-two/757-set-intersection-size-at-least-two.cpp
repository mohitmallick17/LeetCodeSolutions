class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &l, auto &r){
            return (l[1] != r[1] ? l[1] < r[1] : l[0] > r[0]);
        });
        
        int ans = 0;
        int largest=-1, second=-1;
        
        for(auto &i:intervals){
            auto start=i[0], end=i[1];
            bool largest_in_range = (largest >= start);
            bool second_in_range = (second >= start);
            
            if(largest_in_range and second_in_range)continue;
            
            ans += (largest_in_range) ? 1 : 2;
            
            second = (largest_in_range) ? largest : end-1;
            largest = end;
        }
        return ans;
    }
};