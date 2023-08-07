//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool matching(char x,char y){
        if((x=='(' and y==')') or (x=='[' and y==']') or (x=='{' and y=='}')) return true;
        return false;
    }
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        
        for(int i=0;i<x.length();i++){
            if(x[i]=='(' or x[i]=='[' or x[i]=='{'){
                st.push(x[i]);
            }
            else if(x[i]==')' or x[i]==']' or x[i]=='}'){
                if(!st.empty() and matching(st.top(),x[i])) st.pop();
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends