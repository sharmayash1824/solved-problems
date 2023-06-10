//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        set<char> s(str.begin(), str.end());
        
        int start = 0;
        int ans = INT_MAX;
        
        unordered_map<char, int> m;
        
        for(int end = 0; end < str.length(); end++) {
            m[str[end]]++;
            
            while(start <= end && m.size() == s.size()) {
                ans = min(ans, end - start + 1);
                
                m[str[start]]--;
                
                if(m[str[start]] == 0) {
                    m.erase(str[start]);
                }
                
                start++;
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends