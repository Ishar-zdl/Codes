/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-08 09:37:57 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-08 09:49:28
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
const int N=2e3+10;
int n,head[N],tot,q[N],cnt,dis[N][N];
char ch[N];
struct edge{int v,next;}e[N*2];
inline void add(int u,int v){e[++tot]={v,head[u]},head[u]=tot;}
void dfs(int x,int fa,int root){
    for(int i=head[x];i;i=e[i].next){
        int y=e[i].v;
        if(y!=fa)dis[root][y]=dis[root][x]+1,dfs(y,x,root);
    }
}
int main(){
    CIN_sync();
    std::cin>>n>>ch+1;
    for(int i=1;i<=n;++i)if(ch[i]=='1')q[++cnt]=i;
    for(int i=1,u,v;i<n;++i)std::cin>>u>>v,add(u,v),add(v,u);
    for(int i=1;i<=cnt;++i)dfs(i,i,i);
    
}