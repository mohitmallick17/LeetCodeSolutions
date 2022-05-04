// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}// } Driver Code Ends

struct pizza{
    int delivery;
    int index;
    pizza(int d, int i) : delivery(d), index(i) {}
    
    
};
bool cmp(pizza &a, pizza &b){
    if(a.delivery==b.delivery)return a.index < b.index;
    return a.delivery<b.delivery;
}
vector<int> permute(vector<vector<int>> &arr, int n){
    vector<pizza> v;
    for(int i=0;i<arr.size();i++){
        v.push_back(pizza(arr[i][0]+arr[i][1], i));
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> res;
    for(auto &x:v){
        res.push_back(x.index + 1);
    }
    return res;
}