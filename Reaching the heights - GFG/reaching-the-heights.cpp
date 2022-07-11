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
    // sort(a, a+1);
    // vector<int> pos(n);
    // int st=0, en=n-1;
    // int sum=0;
    // int idx = 0;
    // while(st < en){
    //     pos[idx++] = a[en];
    //     pos[idx++] = a[st];
    //     sum += a[en--] + a[st++];
        
    // }
    // if(st==en){
    //     if(st&1)
    //         pos[idx] = a[st], sum-=a[st];
    //     else
    //         pos[idx] = a[en], sum+=a[en];
    // }
    // return sum==0 ? vector<int>{-1}:pos;

    sort(a , a+n) ;         //start ke N/2 elements are minimum and after that N/2 elements are maximum
   vector<int> ans(n) ; 
   
   int sum = 0 ;                   //To check kya last me ham Ground floor par hi wapas aa gye 
   
   int maxEle = n-1 ;              //maximum elements INDEX 
   for(int i=0; i<n ; i+=2)        //FILL maximum element at ODD index                        
   {               
       ans[i] = a[maxEle] ; 
       maxEle-- ; 
       sum += ans[i] ; 
   }
   
   int minEle = 0 ;                //maximum elements INDEX 
   for(int i=1 ; i<n ; i+=2)
   {
       ans[i] = a[minEle] ; 
       minEle++ ; 
       sum -= ans[i] ; 
   }
   
   if(sum == 0)return {-1} ; 
   
   return ans ;   
}

