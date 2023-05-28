//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    int open=0;
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='{')open++;
        else{
            if(open>0)open--;
            else{
                open++;
                ans++;
            }
        }
    }
    if(open%2!=0)return -1;
    return ans+open/2;
}