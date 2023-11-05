//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool placable(int r, int c, vector<vector<int>> &board, int n)
    {
        for (int i = r - 1; i >= 0; i--)
        {
            if (board[i][c] == 1)
            {
                return false;
            }
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 1)
            {
                return false;
            }
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 1)
            {
                return false;
            }
        }
        return true;
    }
    void nqueen(int r, vector<vector<int>> &board, vector<vector<int>> &temp, int n)
    {
        if (r == n)
        {
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == 1)
                    {
                        ans.push_back(j + 1);
                    }
                }
            }
            temp.push_back(ans);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (placable(r, i, board, n))
            {
                board[r][i] = 1;
                nqueen(r + 1, board, temp, n);
                board[r][i] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> temp;
        nqueen(0, board, temp, n);
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

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends