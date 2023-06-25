//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int findMaxSum(vector<int>& a){
      //Code Here
      int n = a.size();
        vector<int> curr(3, 0);
        vector<int> next(3, 0);
        
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=2; j++){
                int hit = 0;
                if(j<2){
                    hit = a[i]+next[j+1];
                }
                
                int mis = next[0];
                curr[j] = max(mis, hit);
            }
            next = curr;
        }
        
        return next[0];
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends