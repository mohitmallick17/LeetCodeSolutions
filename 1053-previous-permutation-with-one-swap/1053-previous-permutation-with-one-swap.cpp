class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n=arr.size();
        int incorrect_pos = -1;
        for(int i=n-1;i>0;i--){
            if(arr[i-1] > arr[i]){
                incorrect_pos = i-1;
                break;
            }
        }
        if(incorrect_pos==-1)return arr;
        
        for(int i=n-1;i>incorrect_pos;i--){
            // sorted in descending
            // need: largest element < arr[incorrect_pos]. And if duplicates, take leftmost one
            // since already decreasing, if found duplicates, just move left
            if(arr[incorrect_pos] > arr[i] and arr[i] != arr[i-1]){
                swap(arr[i], arr[incorrect_pos]);
                break;
            }
        }
        return arr;
    }
};