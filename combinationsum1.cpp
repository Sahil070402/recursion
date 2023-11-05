//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    void cs(int i, int target, int n, vector<int> &ans, vector<vector<int>> &temp, vector<int> &a)
    {
        if (i == n)
        {
            if (target == 0)
            {
                temp.push_back(ans);
                return;
            }
            return;
        }
        if (a[i] <= target)
        {
            ans.push_back(a[i]);
            cs(i, target - a[i], n, ans, temp, a);
            ans.pop_back();
        }
        cs(i + 1, target, n, ans, temp, a);
    }
    vector<vector<int>> combinationSum(vector<int> &a, int b)
    {
        set<int> st(a.begin(), a.end());
        vector<int> arr(st.begin(), st.end());
        int n = arr.size();
        vector<vector<int>> temp;
        vector<int> ans;
        cs(0, b, n, ans, temp, arr);
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
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}
// } Driver Code Ends