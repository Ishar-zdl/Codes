/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-04 20:31:27 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-04 21:15:41
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
const int N=2e5+10;
bool vis[N];
int tot,head[N],color[N],fa[N];
struct edge{int v,next;}e[N*2];
inline void add(int u,int v){e[++tot]={v,head[u]};head[u]=tot;}
std::map<std::pair<int,int>,int>mp;
int a[N],b[N];
void dfs(int x){
    vis[x]=1;
    for(int i=head[x];i;i=e[i].next){
        int y=e[i].v;
        if(!fa[y])fa[y]=x,color[y]=~color[x],dfs(y);
        else if(fa[y]>0){
            if(color[y]==color[x]){std::cout<<"No";exit(0);}
        }
    }
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=m;++i)a[i]=read();
    for(int i=1;i<=m;++i)b[i]=read();
    for(int i=1;i<=m;++i){
        if(a[i]==b[i]){std::cout<<"No";return 0;}
        if(!mp[{a[i],b[i]}]&&!mp[{b[i],a[i]}]){
            mp[{a[i],b[i]}]=mp[{b[i],a[i]}]=1;
            add(a[i],b[i]);add(b[i],a[i]);
        }
    }
    for(int i=1;i<=n;++i){
        if(!vis[i])fa[i]=-1,color[i]=1,dfs(i);
    }
    std::cout<<"Yes";
}