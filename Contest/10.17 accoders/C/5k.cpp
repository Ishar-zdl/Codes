%:include <cstdio>
%:include <cstring>
%:include <vector>
%:include <algorithm>
%:include <unordered_map>
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)

using namespace std;
char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
int n, X, Y, l1[500050], r1[500050], l2[500050], r2[500050];
inline int R()
{
    int q = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        q = q * 10 + c - '0', c = getchar();
    return q;
}
struct S
{
    struct Z
    {
        int x, y;
        bool operator<(Z b) const { return x < b.x; }
    };
    int c, b[1000050], U[1000050], V[1000050];
    Z P[1000050];
    int Q(int *l, int *r, int X)
    {
        unordered_map<unsigned long long, int> C;
        int m = 0, q = 0;
        unsigned long long Z = 0;
        b[++m] = 0;
        b[++m] = X;
        for (int i = 1; i <= n; ++i)
            b[++m] = l[i], b[++m] = r[i], U[i] = rand(), V[i] = rand();
        sort(b + 1, b + m + 1);
        m = unique(b + 1, b + m + 1) - b - 1;
        c = 0;
        for (int i = 1; i <= n; ++i)
        {
            P[++c] = {l[i] = lower_bound(b + 1, b + m + 1, l[i]) - b, i};
            P[++c] = {r[i] = lower_bound(b + 1, b + m + 1, r[i]) - b, -i};
        }
        sort(P + 1, P + c + 1);
        for (int i = 1; i <= n; ++i)
            Z += U[i];
        for (int i = 1, p = 0; i < m; ++i)
        {
            while (p < c && P[p + 1].x <= i)
            {
                ++p;
                if (P[p].y > 0)
                    Z = Z - U[P[p].y] + V[P[p].y];
                else
                    Z = Z - V[-P[p].y] + U[-P[p].y];
            }
            q = max(q, C[Z] += b[i + 1] - b[i]);
        }
        return q;
    }
} SA;
signed main()
{
    freopen("globe.in", "r", stdin);
    freopen("globe.out", "w", stdout);
    srand(388651);
    n = R();
    X = R();
    Y = R();
    for (int i = 1; i <= n; ++i)
        l1[i] = R(), l2[i] = R(), r1[i] = R(), r2[i] = R();
    printf("%lld", 1ll * SA.Q(l1, r1, X) * SA.Q(l2, r2, Y));
    return 0;
}
