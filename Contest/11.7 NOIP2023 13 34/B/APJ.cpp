// ubsan: undefined
// accoders
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000005, P = 1000000007;
int n, c;
long long m;
long long l[MAXN], r[MAXN], p[MAXN];
pair<int, int> opt[MAXN];
int f(int n) { return 1ll * n * (n + 1) / 2 % P; }
void del(int &a, int b) { a -= b; (a < 0) && (a += P); }
void add(int &a, int b) { a += b; (a >= P) && (a -= P); }
int qpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1ll * ans * a % P;
        a = 1ll * a * a % P;
        b >>= 1;
    }
    return ans;
}
int main() {
    // freopen("competition.in", "r", stdin);
    // freopen("competition.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld%lld", &l[i], &r[i]), p[++c] = l[i], p[++c] = r[i] + 1;
    p[++c] = 1;
    sort(p + 1, p + 1 + c);
    c = unique(p + 1, p + 1 + c) - p - 1;
    p[c + 1] = m + 1;
    for (int i = 1; i <= n; i++) {
        l[i] = lower_bound(p + 1, p + 1 + c, l[i]) - p;
        r[i] = lower_bound(p + 1, p + 1 + c, r[i] + 1) - p;
        opt[2 * i - 1] = { l[i], i };
        opt[2 * i] = { r[i], -i };
    }
    sort(opt + 1, opt + 1 + 2 * n);
    int ans = 0;
    int now = f(n);
    set<int> s;
    s.insert(0), s.insert(n + 1);
    int it = 1;
    for (int i = 1; i <= c; i++) {
        while (it != 2 * n + 1 && opt[it].first == i) {
            int k = opt[it].second;
            if (k > 0) {
                auto it = s.insert(k).first;
                int l = *prev(it), r = *next(it);
                del(now, f(r - l - 1)), add(now, f(k - l - 1)), add(now, f(r - k - 1));
            } else {
                k *= -1;
                auto it = s.lower_bound(k);
                int l = *prev(it), r = *next(it);
                add(now, f(r - l - 1)), del(now, f(k - l - 1)), del(now, f(r - k - 1));
                s.erase(it);
            }
            it++;
        }
        ans = (ans + (p[i + 1] - p[i]) % P * now) % P;
    }
    ans = (m - 1ll * ans * qpow(f(n), P - 2) % P + P) % P;
    printf("%d\n", ans);
    return 0;
}
/*
3 10000
2432 2823
1637 2899
2637 5236
*/