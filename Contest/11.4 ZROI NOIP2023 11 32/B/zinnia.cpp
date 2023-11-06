/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-04 09:43:29 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-04 12:08:59
 */
#include<bits/stdc++.h>
#define int long long
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
const int N=3e5+5,inf=0x3f3f3f3f3f3f3f3f;
int n,m,head[N],tot,dis[N],step[N];
bool vis[N];
std::queue<int>q;
struct edge{int v,next,w;}e[N];
inline void add(int u,int v,int w){e[++tot]={v,head[u],w};head[u]=tot;}
inline bool check(int x){
    for(int i=1;i<=n;++i)dis[i]=inf;
    dis[1]=0;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int d=dis[u]+1;
        for(int i=head[u],v,w;i;i=e[i].next){
            v=e[i].v,w=e[i].w;
            if(d*w>x)continue;
            if(dis[v]==inf){
                dis[v]=d;q.push(v);
            }
        }
    }
    return dis[n]!=inf;
}
signed main(){
    freopen("zinnia.in","r",stdin),freopen("zinnia.out","w",stdout);
    n=read(),m=read();   
    for(int i=1,u,v,w;i<=m;++i){
        u=read(),v=read(),w=read();
        add(u,v,w);
    }
    int r=3e14,l=1;
    int ans;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%lld",ans);
}