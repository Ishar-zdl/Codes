/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-26 20:50:32 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-28 16:56:50
 */
#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}
int n,m,tot,head[N],qu,d[N],f[N][20],ma[N][20],fa[N];
bool vis[N];
struct edge{
    int w,u,v,next;
    bool operator<(edge b)const{return w>b.w;}
}e[N],edge[N*2];
inline int get(int x){
    if(x==fa[x])return x;
    return fa[x]=get(fa[x]);
}
void kruskal(){
    for(int i=1;i<=m;i++)
        e[i].u=read(),e[i].v=read(),e[i].w=read();
    sort(e+1,e+m+1);int sum=0;
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=m&&sum<n;++i){
        int x=get(e[i].u),y=get(e[i].v);
        // cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;
        if(x==y)continue;
        sum++;fa[x]=y;
        // cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;
        edge[++tot]={e[i].w,e[i].u,e[i].v,head[e[i].u]};head[e[i].u]=tot;
        edge[++tot]={e[i].w,e[i].v,e[i].u,head[e[i].v]};head[e[i].v]=tot;
    }
}
void dfs(int x,int die,int q){
    vis[x]=1;
    d[x]=d[die]+1;f[x][0]=die;ma[x][0]=q;
    // cout<<x<<' '<<' '<<d[x]<<' '<<q<<endl;
    int k=d[x]?__lg(d[x]):0;
    for(int i=1;i<=k;i++)f[x][i]=f[f[x][i-1]][i-1],ma[x][i]=min(ma[x][i-1],ma[f[x][i-1]][i-1]);
    for(int i=head[x];i;i=edge[i].next)
        if(edge[i].v!=die)dfs(edge[i].v,x,edge[i].w);
}
inline void lca(int a,int b){
    // cout<<a<<b<<endl;
    if(get(a)^get(b)){printf("-1\n");return;}
    if(d[a]<d[b])swap(a,b);int ans=1e8;
    while(d[a]>d[b]){
        // cout<<ma[2][0]<<endl;
        // cout<<a<<' '<<b<<' ';
        // cout<<d[a]-d[b]<<' ';
        // cout<<__lg(d[a]-d[b])<<' ';
        // cout<<ma[a][__lg(d[a]-d[b])]<<endl;
        ans=min(ans,ma[a][__lg(d[a]-d[b])]),a=f[a][__lg(d[a]-d[b])];
    }
    if(a==b){write(ans);putchar('\n');return;}
    // cout<<"fdskl"<<endl;
    for(int i=__lg(d[b]);i>=0;--i)
        if(f[a][i]!=f[b][i])ans=min(ans,min(ma[a][i],ma[b][i])),a=f[a][i],b=f[b][i];
    // cout<<f[a][0]<<" fdks"<<endl;
    ans=min(ans,min(ma[a][0],ma[b][0]));
    write(ans);putchar('\n');
}
void work(){
    // qu=read();cout<<qu<<"fdkls"<<endl;
    qu=read();
    for(int i=1,a,b;i<=qu;i++)
        a=read(),b=read(),lca(a,b);
}
int main(){
    n=read(),m=read();d[0]=-1;
    kruskal();
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,0,0);
    }
    // cout<<endl;
    // for(int i=1;i<=n;i++)cout<<d[i]<<' ';cout<<endl;
    work();
}