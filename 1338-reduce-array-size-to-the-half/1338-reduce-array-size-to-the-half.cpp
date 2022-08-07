class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n=arr.size();
        for(int &a:arr)mp[a]++;
        
        vector<int> freq_arr(n+1, 0);
        for(auto &x:mp){
            freq_arr[x.second]++; // increase count of freqency K
        }
        int len=0;
        int cnt=0;
        for(int i=freq_arr.size()-1;i>0 and len < n/2;i--){
            while(freq_arr[i] > 0  and len < n/2){
                len+=i;
                freq_arr[i]--;
                cnt++;
            }
        }
        return cnt;
    }
};