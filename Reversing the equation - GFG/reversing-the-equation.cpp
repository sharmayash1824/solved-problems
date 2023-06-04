//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            stack<string> st;
            string temp = "";
            
            for(int i=0; i<s.size(); i++) {
                if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                    st.push(temp);
                    temp = s[i];
                    st.push(temp);
                    temp = "";
                }
                else {
                    temp += s[i];
                }
            }
            
            if(temp != "") st.push(temp);
            
            string ans = "";
            
            while(!st.empty()) {
                ans += st.top();
                st.pop();
            }
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends