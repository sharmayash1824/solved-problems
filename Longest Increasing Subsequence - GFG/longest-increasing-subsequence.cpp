//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> arr;
       for(int i=0;i<n;i++){
           arr.push_back(a[i]);
       }
       vector<int> ans;
       ans.push_back(arr[0]);
       int l=1;
       for(int i=1;i<n;i++){
           if(arr[i]>ans[l-1]){
               ans.push_back(arr[i]);
               l++;
           }
           else{
               auto it = lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
               ans[it]=arr[i];
           }
       }
       return l;
       
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends