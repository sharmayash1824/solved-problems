//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        int ans = 0;
        unordered_map<char,int> mp;
        for(auto i : A) mp[i]++;
        for(auto i : B) mp[i]--;
        for(auto it : mp){
            if(it.second!=0) return -1;
        }
        
        int i = A.size();
        int j = B.size();
        while(i>=0 and j>=0){
            if(A[i]==B[j]){
                 i--;
                 j--;
            }
            else{
                i--;
                ans++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends