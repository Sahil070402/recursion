#include <bits/stdc++.h>
using namespace std;
bool sub(int i, int *a, vector<int> &ans, int s, int sum, int n)
{
    if (i == n)
    {
        if (s == sum)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    ans.push_back(a[i]);
    s += a[i];
    if (sub(i + 1, a, ans, s, sum, n) == true)
    {
        return true;
    }
    ans.pop_back();
    s -= a[i];
    if (sub(i + 1, a, ans, s, sum, n) == true)
    {
        return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    vector<int> ans;
    int arr[3] = {1, 2, 1};
    int sum = 2;
    sub(0, arr, ans, 0, sum, 3);
    return 0;
}
