//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        
        // sn = sum      s2n = sum of squares
        sort(arr.begin(),arr.end());
        int mis = -1;
        int rep = -1;
        for(int i =1;i<n;i++){
            if(arr[i]-arr[i-1]>1){
                mis = (arr[i]+arr[i-1])/2;
            }
            else if(arr[i]-arr[i-1]==0){
                rep = arr[i];
            }
        }
        if(arr[0]!=1){
            mis=1;
        }
        if(mis==-1){
            mis = n;
        }
        
        return {rep,mis};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends