/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-19 09:10:00 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-19 11:25:09
 */
#include<bits/stdc++.h>
using namespace std;
#define N (int)(5e5+5)
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
    if(de[a]<de[b])swap(a,b);
    while(de[a]>de[b]){
        a=f[a][__lg(de[a]-de[b])];
    }
    if(b==a)return b;
    for(int i=__lg(de[a]);i>=0;--i)
        if(f[a][i]!=f[b][i])a=f[a][i],b=f[b][i];
    return f[a][0];
}
int main(){
    freopen("game.in","r",stdin),freopen("game.out","w",stdout);
    n=read();de[0]=-1;
    for(int i=1,a,b,c;i<n;i++){
        a=read(),b=read(),c=read();
        add(a,b,c);add(b,a,c);
    }
    dfs(1,0);
    int k=read();
    for(int i=1,a;i<=k;++i){
        int l=read(),r=read(),ans=1e9;a=read();
        for(int j=l;j<=r;++j){
            if(j==a)continue;
            ans=min(ans,d[a]+d[j]-2*d[lca(a,j)]);
        }
        printf("%d\n",ans);
    }
}