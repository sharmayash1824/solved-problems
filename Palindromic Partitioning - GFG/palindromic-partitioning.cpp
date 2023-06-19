//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[501][501];
    
    bool isPalindrome(string s, int i, int j){
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string s, int i, int j){
       
        if(i>=j) return 0;
        
        if(isPalindrome(s, i, j)) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        int mn = INT_MAX;
        for(int k = i ;k<j ;k++)
        {
            int l, r;
            
            if(t[i][k] != -1){
                l = t[i][k];
            }
            else{
                l = solve(s, i, k);
                t[i][k] = l;
            }
            
            if(t[k+1][j] != -1 ){
                r = t[k+1][j];
            }
            else{
                r = r = solve(s, k+1, j);
                t[k+1][j] = r;
            }
            
            int ans =  1 + l + r;
            mn = min(mn, ans);
        }
        return t[i][j] = mn;
    }

    int palindromicPartition(string str)
    {
        memset(t, -1, sizeof(t));
        int i=0 , j=str.length()-1;
        return solve(str, i, j);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends