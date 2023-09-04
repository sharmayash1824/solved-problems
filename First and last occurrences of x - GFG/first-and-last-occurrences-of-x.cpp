//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int helper(int low,int high,int x,int arr[],bool flag){
        
        int ans = -1;
        while(low<=high){
            int mid = (high+low)/2;
            if(arr[mid]>x){
                high=mid-1;
            }
            else if(arr[mid]<x){
                low=mid+1;
            }
            else{
                ans = mid;
                if(flag){
                    high = mid-1;
                }
                else{
                    low=mid+1;    
                }
            }
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        bool first = true;
        vector<int> ans;
        ans.push_back(helper(0,n-1,x,arr,first));
        first=!first;
        ans.push_back(helper(0,n-1,x,arr,first));
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends