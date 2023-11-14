#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
const int MAXN=5e5+10;
int n,m,k,a[MAXN],c[MAXN];
vector <int> v[MAXN];
int main()
{
    // freopen("opt.in","r",stdin);
    // freopen("opt.out","w",stdout);
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>c[i];c[1]=0;
    for(int i=1;i<=m;++i)
        for(int j=i;j<=m;j+=i)
            v[j].push_back(i);
    for(int i=1;i<=m;++i)
        for(int x:v[i])
            c[i]=min(c[i],c[x]+c[i/x]);
    for(int i=m-1;i;--i) c[i]=min(c[i],c[i+1]);
    for(int i=1;i<=m;++i) c[m]=min(c[m],c[i]+c[(int)ceil(m*1.0/i)]);
    for(int i=m-1;i;--i) c[i]=min(c[i],c[i+1]);
    for(int i=1;i<=m;++i) cout<<c[i]<<' ';cout<<'\n';
    sort(a+1,a+1+n);int l=0,r=m;
    while(l<r)
    {
        int mid=(l+r)>>1;long long sum=0;
        for(int i=1,j=1;i<=(n+1)/2;++i)
        {
            while(a[i]/j>mid) ++j;
            sum+=c[j];
        }
        (sum<=k)?r=mid:l=mid+1;
    }
    cout<<l<<'\n';return 0;
}