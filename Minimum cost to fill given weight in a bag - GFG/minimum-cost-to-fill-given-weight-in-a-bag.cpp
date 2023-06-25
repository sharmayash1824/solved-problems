//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int dp[201][201];
	int func(int cost[],int n,int W){
	    if(n==-1 and W==0){
	        return 0;
	    }
	    if(n==-1){
	        return 1e9;
	    }
	    if(W==0){
	        return 0;
	    }
	    if(dp[n][W]!=-1){
	        return dp[n][W];
	    }
	    
	    if((n+1)>W or cost[n]==-1) return dp[n][W] = func(cost,n-1,W);
	    
	    int x = func(cost,n-1,W);
	    int y = cost[n] + func(cost,n,W-(n+1));
	    
	    return dp[n][W] = min(x,y);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        memset(dp,-1,sizeof(dp));
        int a = func(cost,N-1,W);
        if(a>=1e9) return -1;
        return a;
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends