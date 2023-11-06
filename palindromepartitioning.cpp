#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool palind(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }
    void parti(string s, int ind, vector<string> &temp, vector<vector<string>> &ans)
    {
        if (ind == s.size())
        {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < s.size(); i++)
        {
            if (palind(s, ind, i))
            {
                temp.push_back(s.substr(ind, i - ind + 1));
                parti(s, i + 1, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        parti(s, 0, temp, ans);
        return ans;
    }
};