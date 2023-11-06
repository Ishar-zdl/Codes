/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-28 19:11:28 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-28 21:41:04
 */
#include<bits/stdc++.h>
using namespace std;
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
const int N=3e5+5;
struct edge{
    int v,next;
}e[N*2];
int ans[N],cha[N],a[N],tot,head[N],d[N],f[N][20];
inline void add(int u,int v){
    e[++tot]={v,head[u]};head[u]=tot;
}
void dfs(int x,int fa){
    d[x]=d[fa]+1;f[x][0]=fa;
    for(int i=1;i<=__lg(d[x]);++i)f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].next)
        if(e[i].v!=fa)dfs(e[i].v,x);
}
inline void lca(int a,int b){
    cha[a]++,cha[b]++;
    if(d[a]<d[b])swap(a,b);
    while(d[a]>d[b])a=f[a][__lg(d[a]-d[b])];
    if(b==a){cha[a]--;cha[f[a][0]]--;return;}
    for(int i=__lg(d[a]);i>=0;--i)
        if(f[a][i]!=f[b][i])a=f[a][i],b=f[b][i];
    int fa=f[a][0];cha[fa]--;cha[f[fa][0]]--;
}
void Dfs(int x,int fa){
    for(int i=head[x];i;i=e[i].next){
        if(e[i].v!=fa)Dfs(e[i].v,x),cha[x]+=cha[e[i].v];
    }
}
int main(){
    int n=read();a[1]=read();
    for(int i=2;i<=n;i++)a[i]=read(),ans[a[i]]--;
    for(int i=1,a,b;i<n;i++)a=read(),b=read(),add(a,b),add(b,a);
    dfs(a[1],0);
    for(int i=2;i<=n;i++)lca(a[i-1],a[i]);
    Dfs(a[1],0);
    for(int i=1;i<=n;i++)write(ans[i]+cha[i]),putchar('\n');
}