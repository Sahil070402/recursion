//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void cs2(int i, vector<int> &ans, int target, vector<vector<int>> &temp, vector<int> &arr)
    {
        if (target == 0)
        {
            temp.push_back(ans);
            return;
        }
        for (int j = i; j < arr.size(); j++)
        {
            if (j > i && (arr[j] == arr[j - 1]))
            {
                continue;
            }
            if (arr[j] > target)
            {
                break;
            }
            ans.push_back(arr[j]);
            cs2(j + 1, ans, target - arr[j], temp, arr);
            ans.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> temp;
        vector<int> ans;
        cs2(0, ans, k, temp, arr);
        return temp;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto obj = ob.CombinationSum2(arr, n, k);
        for (int i = 0; i < obj.size(); i++)
        {
            for (int j = 0; j < obj[i].size(); j++)
            {
                cout << obj[i][j] << " ";
            }
            cout << "\n";
        }
        if (obj.size() == 0)
            cout << "\n";
    }
    return 0;
}
// } Driver Code Ends