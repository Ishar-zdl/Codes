/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-29 06:43:26 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-29 09:57:58
 */
#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e5+10;
int n,m,dep[MAXN],a[MAXN],dis[MAXN],f[MAXN][20];
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],val[MAXN<<1],cnt;
int d[MAXN],CNT,ans;
inline void add(int x,int y,int v)
{
    to[++cnt]=y,nxt[cnt]=head[x];
    head[x]=cnt,val[cnt]=v;return ;
}
struct node{int a,b,d,L;}p[MAXN];
void dfs(int x,int fa=0)
{
    dep[x]=dep[fa]+1,dis[x]=dis[fa]+a[x];f[x][0]=fa;
    for(register int i=1;i<=__lg(dep[x]);++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for(register int i=head[x];i;i=nxt[i])
    {
        int y=to[i];
        if(y==fa) continue;
        a[y]=val[i];dfs(y,x);
    }
    return ;
}
inline int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y]) x=f[x][__lg(dep[x]-dep[y])];
    if(x==y) return x;
    for(register int i=__lg(dep[x]);i>=0;--i)
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
void Do(int x,int fa=0)
{
    for(register int i=head[x];i;i=nxt[i])
    {
        int y=to[i];if(y==fa) continue;
        Do(y,x);d[x]+=d[y];
    }
    if(d[x]==CNT) ans=max(ans,a[x]);return ;
}
inline bool check(int x)
{
    CNT=ans=0;int M=0;memset(d,0,sizeof(d));
    for(register int i=1;i<=n;++i)
    {
        if(p[i].d>x)
        {
            ++CNT;
            d[p[i].a]++,d[p[i].b]++;
            d[p[i].L]-=2;M=max(M,p[i].d);
        }
    }
    Do(1,0);return (M-ans<=x);
}
int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(0);
#endif
    cin>>n>>m;int l=0,r=0;
    for(register int i=1;i<n;++i)
    {
        int x,y,v;cin>>x>>y>>v;
        add(x,y,v),add(y,x,v);
    }
    dfs(1);
    for(register int i=1;i<=m;++i)
    {
        cin>>p[i].a>>p[i].b;p[i].L=lca(p[i].a,p[i].b);
        p[i].d=dis[p[i].a]+dis[p[i].b]-(dis[p[i].L]<<1);
        r=max(r,p[i].d);
    }
    while(l<r)
    {
        int mid=(l+r)>>1;
        (check(mid))?r=mid:l=mid+1;
    }
    cout<<l<<'\n';return 0;
}