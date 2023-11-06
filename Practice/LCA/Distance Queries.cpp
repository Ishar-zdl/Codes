/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-26 16:15:53 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-26 16:58:10
 */
// 树上前缀和，减去LCA的前缀和，没了
#include<bits/stdc++.h>
using namespace std;
#define N (int)(4e4+5)
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
struct lkb{
    int v,next,w;
}e[2*N];
int n,m,head[N],tot,d[N],f[N][21],de[N];
void add(int u,int v,int w){
    e[++tot]={v,head[u],w};head[u]=tot;
}
void dfs(int x,int fa){
    de[x]=de[fa]+1;f[x][0]=fa;
    int k=de[x]?(__lg(de[x])):0;
    for(int i=1;i<=k;i++)f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x],y;i;i=e[i].next){
        if((y=e[i].v)!=fa)d[y]=d[x]+e[i].w,dfs(y,x);
    }
}
inline int lca(int a,int b){
    if(de[a]<de[b])swap(a,b);//int dis=de[a]-de[b];int k=__lg(dis);
    while(de[a]>de[b]){
        a=f[a][__lg(de[a]-de[b])];
    }
    if(b==a)return b;
    for(int i=__lg(de[a]);i>=0;--i)
        if(f[a][i]!=f[b][i])a=f[a][i],b=f[b][i];
    return f[a][0];
}
int main(){
    n=read(),m=read();de[0]=-1;
    for(int i=1,a,b,c;i<=m;i++){
        a=read(),b=read(),c=read();
        char pd=getchar();while(pd<'A'||pd>'Z')pd=getchar();
        add(a,b,c);add(b,a,c);
    }
    dfs(1,0);
    // for(int i=1;i<=n;++i)cout<<d[i]<<' ';cout<<endl;
    int k=read();
    for(int i=1,a,b;i<=k;++i){
        a=read(),b=read();write(d[a]+d[b]-2*d[lca(a,b)]);putchar('\n');
    }
}