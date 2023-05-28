//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        unordered_map<char,char> m,n;
        if(str1.length()!=str2.length()){
            return false;
        }
        
        for(int i=0;i<str1.length();i++){
            if(m.find(str1[i])!=m.end()){
                if(m[str1[i]]!=str2[i]) return false;
            }
            else{
                m[str1[i]]=str2[i];
            }
            if(n.find(str2[i])!=n.end()){
                if(n[str2[i]]!=str1[i]) return false;
            }
            else{
                n[str2[i]]=str1[i];
            }
        }
        
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends