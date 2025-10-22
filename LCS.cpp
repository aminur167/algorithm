#include <bits/stdc++.h>
using namespace std;
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))
using ll = long long;

ll rec(ll i, ll j, string &s, string &t, vector<vector<ll>> &dp)
{

    if (i <= 0 || j <= 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i - 1] == t[j - 1])
    {
        return dp[i][j] = 1 + rec(i - 1, j - 1, s, t, dp);
    }
    else
    {
        return dp[i][j] = max(rec(i - 1, j, s, t, dp), rec(i, j - 1, s, t, dp));
    }
}

void solve()
{
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    ll ans = rec(n, m, s, t, dp);
    string str;

    for (ll i = 0; i < ans; i++)
        str.push_back('0');

    ll indx = ans - 1;
    ll i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            str[indx--] = s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << str << endl;
}

int main()
{
    fastread();
    // ll t;
    // cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}