/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-08 08:57:52 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-08 15:01:50
 */
#include<bits/stdc++.h>
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
const int N=1e6+10;
int q,n,dis[N],ans,head[N],tot=0,lastans;
bool vis[N];
struct edge{int v,next;}e[N*2];
inline void add(int u,int v){e[++tot]={v,head[u]},head[u]=tot;}
void dfs(int x,int last){
    dis[x]=std::min(last,x);
    for(int i=head[x];i;i=e[i].next){
        int y=e[i].v;
        if(!dis[y])dfs(y,dis[x]);
    }
}
int main(){
    freopen("kotori.in","r",stdin);freopen("kotori.out","w",stdout);
    n=read();q=read();ans=1e9;
    for(int i=1,u,v;i<n;++i)u=read(),v=read(),add(u,v),add(v,u);
    int opt=read(),x=read();x%=n;x++;dfs(x,x);
    for(int i=2,opt,x;i<=q;++i){
        opt=read(),x=read();x=(x+lastans)%n+1;
        if(opt==1){
            if(vis[x])continue;
            vis[x]=1;
            ans=std::min(ans,dis[x]);
        }
        else lastans=std::min(dis[x],ans),printf("%d\n",lastans);
    }
}