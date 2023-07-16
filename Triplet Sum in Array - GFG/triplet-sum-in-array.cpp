//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        int start = 0;
        int end = n-1;
        sort(A,A+n);
        for(int i=0;i<n;i++){
            start = i+1;
            end = n-1;
            while(start<end){
                if(A[start]+A[end]>X-A[i]){
                    end--;
                }
                else if(A[start]+A[end]<X-A[i]){
                    start++;
                }
                else if(A[start]+A[end]==X-A[i]){
                    return true;
                }
            }
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends