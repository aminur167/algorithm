#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;
#define all(a) (a).begin(), (a).end()

bool cmp(pll a, pll b) { return a.second == b.second ? a.first < b.first : a.second < b.second; }

void solve()
{
    ll n;
    cin >> n;
    vpl vp(n);
    for (int i = 0; i < n; i++)
        cin >> vp[i].first >> vp[i].second;
    sort(all(vp), cmp);
    ll last = vp[0].second, ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (vp[i].first >= last)
        {
            ans++;
            last = vp[i].second;
        }
    }
    cout << ans + 1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}