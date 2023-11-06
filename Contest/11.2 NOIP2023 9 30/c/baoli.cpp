#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, a, b, x[MAXN];
priority_queue<int> ql;
priority_queue<int, vector<int>, greater<int>> qr;
long long suml, sumr;
int main() {
    // freopen("c.in", "r", stdin);
    // freopen("cout.out", "w", stdout);
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    for (int i = 1; i <= n; i++) {
        if (qr.empty() || x[i] >= qr.top()) qr.push(x[i]), sumr += x[i];
        else ql.push(x[i]), suml += x[i];
        int p = 1ll * i * b / (a + b);
        while (ql.size() < p) sumr -= qr.top(), suml += qr.top(), ql.push(qr.top()), qr.pop();
        while (ql.size() > p) suml -= ql.top(), sumr += ql.top(), qr.push(ql.top()), ql.pop();
        int y = qr.top();
        printf("%lld\n", a * (1ll * ql.size() * y - suml) + b * (sumr - 1ll * qr.size() * y));
    }
    return 0;
}