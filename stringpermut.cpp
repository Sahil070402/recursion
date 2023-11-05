//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Complete this function
    void permut(int i, string s, vector<string> &temp)
    {
        if (i == s.length() - 1)
        {
            temp.push_back(s);
            return;
        }
        for (int j = i; j < s.size(); j++)
        {
            swap(s[i], s[j]);
            permut(i + 1, s, temp);
            swap(s[i], s[j]);
        }
    }

    vector<string> permutation(string S)
    {

        vector<string> temp;
        permut(0, S, temp);
        sort(temp.begin(), temp.end());
        return temp;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> vec = ob.permutation(S);
        for (string s : vec)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends