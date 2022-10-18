//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A){
		vector<int>answer;
		for(int j=0;j<N;j++){
		    int temp1=0;
		    int temp2=j;
		    while(temp1<N and temp2>=0){
		        answer.push_back(A[temp1][temp2]);
		        temp1++;
		        temp2--;
		    }
		}
		for(int i=1;i<N;i++){
		    int temp1=i;
		    int temp2=N-1;
		    while(temp1<N and temp2>=0){
		        answer.push_back(A[temp1][temp2]);
		        temp1++;
		        temp2--;
		    }
		}
		return answer;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends