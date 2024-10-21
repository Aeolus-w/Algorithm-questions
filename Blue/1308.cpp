#include <iostream>
using namespace std;
int n, s;
int h[100005];
int sum[100005];
bool judge(int x) {
    for (int i = 1; i < n - x + 1; i++) {
        if (sum[i + x - 1] - sum[i - 1] < 2 * s)return false;
    }
    return true;
}
int main() {
    int l, r;
    cin >> n >> s;
    sum[0] = 0;
    for (int i = 1; i < n; i++)cin >> h[i], sum[i] = sum[i - 1] + h[i];
    l = 1;
    r = n;
    while (l != r) {
        if (judge((l + r) / 2))r = (l + r) / 2;
        else l = (l + r) / 2 + 1;
    }
    cout << l;
    return 0;
}