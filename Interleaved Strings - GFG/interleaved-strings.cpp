//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    
    int dp[101][101];
    
    bool solve(string A,string B,string C,int n,int m,int len){
        if(len==0) return true;
        if(dp[n][m]!=-1) return dp[n][m];
        
        int a,b;
        a=b=0;
        
        if(n-1>=0 and A[n-1]==C[len-1]) a = solve(A,B,C,n-1,m,len-1);
        if(m-1>=0 and B[m-1]==C[len-1]) b = solve(A,B,C,n,m-1,len-1);
        
        return dp[n][m]= a or b;
        
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n = A.length();
        int m = B.length();
        int len = C.length();
        if(len!=n+m){
            return false;
        }
        memset(dp,-1,sizeof(dp));
        return solve(A,B,C,n,m,len);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends