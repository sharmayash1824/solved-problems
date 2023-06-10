//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        set<vector<int>> s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int low = j+1;
                int high = n-1;
                while(low<high){
                    
                    if(arr[i]+arr[j]+arr[low]+arr[high]==k){
                        s.insert({arr[i],arr[j],arr[low],arr[high]});
                        low++;
                        high=n-1;
                    }
                    else if(arr[i]+arr[j]+arr[low]+arr[high]>k){
                        high--;
                    }
                    else{
                        low++;
                    }
                }
            }
            
        }
        
        for(auto &f:s){
            ans.push_back(f);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends