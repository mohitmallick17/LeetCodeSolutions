class Solution {
    long long minSumArr(vector<int>& v, int k){
        long long sum=0;
        for(int i=0;i<k;i++)sum+=v[i];
        long long ans = sum;
        for(int i=k;i<v.size();i++){
            sum += v[i] - v[i-k];
            ans = min(ans, sum);
        }
        return ans;
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long sum=0;
        for(int &x:cardPoints)sum+=x;
        return sum - minSumArr(cardPoints, cardPoints.size()-k);
    }
};