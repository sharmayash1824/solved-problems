//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array
    long long merge(long long N,long long arr[],long long start,long long mid,long long end){
        long long temp[N];
        long long int i = start;
        long long int j = mid+1;
        long long count = 0;
        long long k = start;
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                temp[k] = arr[i];
                k++;
                i++;
            }
            else{
                temp[k] = arr[j];
                count += (mid-i+1);
                j++;
                k++;
                
            }
        }
        
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=end){
            temp[k++]=arr[j++];
        }
        
        for(long long t=start;t<=end;t++){
            arr[t] = temp[t];
        }
    //   for(long long t=mid+1;t<=end;t++){
    //         arr[t] = temp[t];
    //     }
        return count;
    }
    long long mergeSort(long long N,long long arr[],long long int start,long long int end){
        long long count = 0;
        if(start<end){
            long long int mid = (start+end)/2;
            count +=mergeSort(N,arr,start,mid);
            count +=mergeSort(N,arr,mid+1,end);
            count +=merge(N,arr,start,mid,end);
        }
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code 
        return mergeSort(N,arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends