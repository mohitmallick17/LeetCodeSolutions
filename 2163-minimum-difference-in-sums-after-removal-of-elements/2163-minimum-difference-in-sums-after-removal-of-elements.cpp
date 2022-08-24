class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size()/3;
        long long sum = 0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            sum += nums[i];
            pq.push(nums[i]);
        }
        vector<long long> pre_min;
        pre_min.push_back(sum);
        
        for(int i=n;i<2*n;i++){
            if(nums[i] < pq.top()){ // if cur num < max ele, we will remove max ele and add cur_num
                int del = pq.top();
                pq.pop();
                sum -= del;
                pq.push(nums[i]);
                sum += nums[i];
            }
            pre_min.push_back(sum);
        }
        sum=0;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        for(int i=2*n;i<3*n;i++){
            sum += nums[i];
            min_pq.push(nums[i]);
        }
        
        vector<long long> suf_max;
        suf_max.push_back(sum);
        
        for(int i=2*n - 1;i>=n;i--){
            if(nums[i] > min_pq.top()){
                int del = min_pq.top();
                min_pq.pop();
                sum -= del;
                min_pq.push(nums[i]);
                sum += nums[i];
            }
            suf_max.push_back(sum);
        }
        reverse(suf_max.begin(), suf_max.end());
        long long ans=LONG_MAX;
        // for(auto &x:pre_min)cout << x << ' ';
        // cout << '\n';
        // for(auto &x:suf_max)cout << x << ' ';
        // cout << '\n';
        for(int i=0;i<pre_min.size();i++)
            ans = min(ans, pre_min[i] - suf_max[i]);
        return ans;
        
    }
};