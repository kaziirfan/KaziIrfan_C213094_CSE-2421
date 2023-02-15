#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2e5 + 123;
int knapsack(int p[], int wt[], int W, int n)
{
    int t[n + 1][W + 1];
    memset(t, -1, sizeof(t));
    if (W == 0 || n == 0)
    {
        return 0;
    }
    if (t[n][W] != -1)
    {
        return t[n][W];
    }
    if (wt[n - 1] <= W)
    {
        return t[n][W] = max(p[n - 1] + knapsack(p, wt, W - wt[n - 1], n - 1), knapsack(p, wt, W, n - 1));
    }
    else
    {
        return t[n][W] = knapsack(p, wt, W, n - 1);
    }
}
int main()
{
    int p[mx], wt[mx];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    int W;
    cin >> W;
    cout <<"Ans:"<< knapsack(p, wt, W, n) << endl;
    return 0;
}
