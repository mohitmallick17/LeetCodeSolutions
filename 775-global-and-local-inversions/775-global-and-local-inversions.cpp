class Solution {
    
    long long merge(long long low, long long mid, long long high, vector<int>&a, vector<int>&tmp){
        long long i=low, j=mid, k=low, count=0;
        
        while(i<mid and j<=high){
            if(a[i] <= a[j])
                tmp[k++] = a[i++];
            else{
                tmp[k++] = a[j++];
                count += mid-i;
            }
        }
        while(i < mid)
            tmp[k++] = a[i++];
        while(j <= high)
            tmp[k++] = a[j++];
        for(long long x=low;x<=high;x++)
            a[x]=tmp[x];
        return count;
    }
    long long mergeSort(long long low, long long high, vector<int>&a, vector<int>&tmp){
        long long mid, count = 0LL;
        if(low < high){
            mid = low + (high-low)/2;
            count += mergeSort(low, mid, a, tmp);
            count += mergeSort(mid+1, high, a, tmp);
            count += merge(low, mid+1, high, a, tmp);
        }
        return count;
    }
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(vector<int>&a){
        vector<int> tmp(a.size());
        return mergeSort(0, a.size()-1, a, tmp);
    }
    
    int getLocals(vector<int>& a){
        int cnt=0;
        for(int i=0;i<a.size()-1;i++){
            if(a[i] > a[i+1])cnt++;
        }
        return cnt;
    }
public:
    bool isIdealPermutation(vector<int>& nums) {
        int locals = getLocals(nums);
        int globals = inversionCount(nums);
        
        return globals == locals;
    }
};