/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-15 18:57:04 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-15 19:54:11
 */
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define FRE freopen("sakuya.in","r",stdin),freopen("sakuya.out","w",stdout);
inline int read(){
    char ch=getchar();int x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void CIN_sync(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
}
const int N=5e5+10,mod=998244353;
int n,m,head[N],tot,siz[N],w[N],ny,q,ans=0;
bool vis[N],pd[N];
struct edge{int v,next,w;}e[N*2];
inline void add(int u,int v,int w){e[++tot]={v,head[u],w};head[u]=tot;}
inline int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
void dfs(int x){
    if(pd[x])siz[x]=1;
    vis[x]=true;
    for(int i=head[x];i;i=e[i].next){
        int y=e[i].v;
        if(vis[y])continue;
        dfs(y);siz[x]+=siz[y];
        w[x]=(w[x]+siz[y]*(m-siz[y])%mod*ny%mod*2)%mod;
        w[y]=(w[y]+siz[y]*(m-siz[y])%mod*ny%mod*2)%mod;
        ans=(ans+siz[y]*(m-siz[y])%mod*ny%mod*2%mod*e[i].w)%mod;
    }
}
main(){
    FRE
    n=read(),m=read();ny=qpow(m,mod-2);
    for(int i=1,u,v,w;i<n;++i){
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
    for(int i=1;i<=m;++i)pd[read()]=true;
    dfs(1);
    q=read();
    for(int i=1,x,k;i<=q;++i){
        x=read(),k=read();
        ans=(ans+w[x]*k%mod)%mod;
        printf("%lld\n",ans);
    }
}