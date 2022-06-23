class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1] != b[1])return a[1]<b[1];
        return a[0]<b[0];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pq;
        int time_ = 0;
        for(auto &c:courses){
            // check if duration <= deadline
            if(c[0] <= c[1]){
                if(time_ + c[0] <= c[1]){
                    time_+=c[0];
                    pq.push(c[0]);
                }else{
                    if(!pq.empty() and pq.top() > c[0]){
                        time_ -= pq.top();
                        pq.pop();
                        time_ += c[0];
                        pq.push(c[0]);
                    }
                }
            }
        }
        return pq.size();
    }
};