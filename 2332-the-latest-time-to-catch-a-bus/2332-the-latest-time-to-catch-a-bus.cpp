class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity){
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int m=buses.size(), n=passengers.size();
        
        for(int i=0, j=0;i<m;i++){
            int cnt=0;
            while(j<n and passengers[j] <= buses[i] and cnt<capacity)cnt++, j++;
            
            if(i==m-1){
                // still space left in the last bus (valid passengers < bus*capacity)
                // valid passener = passenger who can get into the bus
                if(cnt < capacity){
                    // just find the last position(time) where there is no passenger
                    int ans = buses.back();
                    j--; // j moved out of bounds
                    while(j>=0 and ans == passengers[j]){
                        ans--;
                        j--;
                    }
                    return ans;
                }else{
                    // no space even in the last bus (passengers) >= bus*capacity
                   // find the first space where we can adjust person, how? find first pair where a[i-1] != a[i]. basically we are kicking our next passenger out of the bus
                    // ex [10,15] -> we kick 15 by arriving on time=14. so [10,14] catch the bus for capacity=2

                    j--; // j moved out of bounds
                    // as long as 2 passengers are contiguous, we keep sliding.
                    while(j>0 and passengers[j]-passengers[j-1]==1)j--;
                    return passengers[j]-1; // kick jth passenger by arriving on passenger[j]-1 time
                }
            }
        }
        return -1;
    }
};