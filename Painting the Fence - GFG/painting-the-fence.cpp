//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    const int mod = 1e9+7;
    long long solve(int n,int k,vector<int> &dp){
        if(n==1) return k;
        if(n==2) return k*k;
        if(dp[n]!=-1) return dp[n]%mod;
        return dp[n] = ((solve(n-2,k,dp)*(k-1))%mod + (solve(n-1,k,dp)*(k-1))%mod)%mod;
    }
    long long countWays(int n, int k){
        // code here
        vector<int> dp(n+1,-1);
        return solve(n,k,dp);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends