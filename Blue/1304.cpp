#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10, mod = 998244353;
int n, m;
LL x[N], y[N];

int qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (LL)res * a % mod;
        }
        a = (LL)a * a % mod;
        b >>= 1;
    }
    return res;
}

// E[i] = A[i]E[0] + B[i]
// E[n] = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        int d = __gcd(x[i], y[i]);
        x[i] /= d, y[i] /= d;
    }
    LL A = 0, B = 0; // 不必开数组A[],B[],只要开两个变量记录当前的A[i],B[i]即可
    for (int i = n - 1; i >= 0; i--)
    {
        LL p = x[i] * qmi(y[i], mod - 2) % mod, p1 = (LL)(y[i] - x[i]) * qmi(y[i], mod - 2) % mod;
        A = (A * p1 % mod + p) % mod, B = (B * p1 % mod + 1) % mod;
    }
    LL ans = ((LL)-B * qmi(A - 1, mod - 2) % mod + mod) % mod;
    cout << ans << '\n';
    return 0;
}