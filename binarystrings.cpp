//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // #define ll long long
    int modulo = 1e9 + 7;
    ll countStrings(int n)
    {
        int zero_end = 1;
        int one_end = 1;
        int sum = zero_end + one_end;
        if (n == 1)
        {
            return sum;
        }
        int i = 1;
        while (i < n)
        {
            one_end = zero_end % modulo;
            zero_end = sum % modulo;
            sum = one_end + zero_end % modulo;
            i++;
        }
        return sum % modulo;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends