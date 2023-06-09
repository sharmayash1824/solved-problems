//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int solve(int start,int end,int x,int arr[],bool &lower){
    int low = start;
    int high = end;
    int ans = -1;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]<x){
            low = mid+1;
        }
        else if(arr[mid]>x){
            high = mid - 1;
        }
        else{
            ans = mid;
            if(lower) high = mid - 1;
            else low = mid+1;
            
        }
    }
    
    return ans;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans;
    bool lower = true;
    int first = solve(0,n-1,x,arr,lower);
    ans.push_back(first);
    lower=!lower;
    int last = solve(0,n-1,x,arr,lower);
    ans.push_back(last);
    
    return ans;
    
    
}

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
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends