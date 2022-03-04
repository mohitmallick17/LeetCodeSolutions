class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> v(102);
        
        v[0]=poured;
        
        for(int i=1;i<=query_row;i++){
            for(int j=i;j>=0;j--){
                v[j+1] += v[j] = max(0.0, (v[j]-1)/2.0);
            }
        }
        return min(1.0, v[query_glass]);
    }
};