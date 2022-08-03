class cmp{
public:
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[0]+a[1] > b[0]+b[1];
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        // num1 num2 index_of_num2
        for(int i=0;i<nums1.size() and i<k;i++){
            pq.push({nums1[i], nums2[0], 0});
        }
        vector<vector<int>> res;
        while(k-- > 0 and !pq.empty()){
            auto front = pq.top();
            pq.pop();
            int n1=front[0], n2=front[1], i_n2=front[2];
            res.push_back({n1, n2});
            if(i_n2 == nums2.size()-1)continue;
            pq.push({n1, nums2[i_n2+1], i_n2+1});
        }
        return res;
    }
};