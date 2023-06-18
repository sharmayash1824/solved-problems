//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        string A_rev = A; 
        reverse(A_rev.begin(),A_rev.end());
        int n = A.length();
        int t[n+1][n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 or j==0){
                    t[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(A[i-1]==A_rev[j-1]){
                     t[i][j]= 1+ t[i-1][j-1];
                }
                else{
                     t[i][j]= max (t[i][j-1] ,t[i-1][j] );
                }
            }
        }
        
        return t[n][n];
        
        
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends