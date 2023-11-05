//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sss(int i, vector<int> &arr, vector<int> &ans, int sum, int n)
    {
        if (i == n)
        {
            ans.push_back(sum);
            return;
        }

        sss(i + 1, arr, ans, sum + arr[i], n);
        sss(i + 1, arr, ans, sum, n);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum = 0;
        vector<int> ans;
        sss(0, arr, ans, sum, N);
        sort(ans.begin(), ans.end());
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends