#include <bits/stdc++.h>
using namespace std;
void sub(int *a, int i, vector<int> &ans, int n)
{
    if (i == n)
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(a[i]);
    sub(a, i + 1, ans, n);
    ans.pop_back();
    sub(a, i + 1, ans, n);
}
int main(int argc, char const *argv[])
{
    vector<int> ans;
    int arr[3] = {3, 1, 2};
    sub(arr, 0, ans, 3);
    return 0;
}
