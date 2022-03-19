class Solution {
    int complement(int n, int k){
        // complement: 3k - n - 1
        // n = node wholse complement is to be found
        // k = number of nodes in that level where n is present
        return (3*k) - n - 1;
    }
public:
    vector<int> pathInZigZagTree(int label){
        int k=0;
        int adder = 1;
        while(k < label){
            k += adder;
            adder *= 2;
        }
        adder /= 2;
        vector<int> res;
        while(label > 1){
            res.push_back(label);
            int comp = complement(label, adder);
            label = comp/2; // parent
            adder /= 2;
        }
        res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};