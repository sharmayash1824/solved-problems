//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
          fact[i] = i * fact[i - 1];
    
        vector<int> numbers;
        for (int i = 1; i <= n; i++)
          numbers.push_back(i);
    
        k--;
        string ans = "";
        for (int i = 1; i <= n; i++)
        {
          int index = k / fact[n - i];
          ans += (numbers[index] + '0');
          numbers.erase(numbers.begin() + index);
          k -= index * fact[n - i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends