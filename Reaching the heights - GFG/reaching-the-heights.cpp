// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    sort(a, a+n);
    vector<int> pos(n);
    int st=0, en=n-1;
    int sum=0;
    int idx = 0;
    while(st < en){
        pos[idx++] = a[en];
        pos[idx++] = a[st];
        sum += a[en] - a[st];
        en--, st++;
    }
    if(st==en){
        pos[idx] = a[st], sum-=a[st];
    }
    return sum==0 ? vector<int>{-1}:pos;
}
