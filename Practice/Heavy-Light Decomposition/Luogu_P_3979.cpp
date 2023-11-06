/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-05 18:35:20 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-05 18:41:32
 */
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
#define lc p<<1
#define rc p<<1|1
const int N=1e5+10;
int n,m,tot,id,head[N],fa[N],top[N],son[N],siz[N],dep[N],dfn[N],rnk[N],w[N],qu[N];
struct edge{
    int v,next;
}e[N*2];
inline void add(int u,int v){
    e[++tot]={v,head[u]},head[u]=tot;
}
void dfs1(int x){
    siz[x]=1;
    for(int i=head[x],y;i;i=e[i].next)
        if(!dep[y=e[i].v]){
            dep[y]=dep[x]+1;fa[y]=x;
            dfs1(y);siz[x]+=siz[y];
            if(!son[x]||siz[y]>siz[son[x]])son[x]=y;
        }
}
void dfs2(int x,int t){
    dfn[x]=++tot;rnk[tot]=x;top[x]=t;
    if(!son[x]){qu[x]=tot;return;}
    dfs2(son[x],t);
    for(int i=head[x],y;i;i=e[i].next){
        y=e[i].v;
        if(y!=fa[x]&&y!=son[x])dfs2(y,y);
    }qu[x]=tot;
}
struct segment_tree{
    int l,r,sum,cha;
    #define l(p) t[p].l
    #define r(p) t[p].r
    #define sum(p) t[p].sum
    #define cha(p) t[p].cha
}t[N*4];
inline void build(int p,int l,int r){
    l(p)=l,r(p)=r;cha(p)=-1;
    if(l==r){sum(p)=w[rnk[l]];return;}
    int mid=l+r>>1;
    build(lc,l,mid),build(rc,mid+1,r);
    sum(p)=min(sum(lc),sum(rc));
}
inline void pushdown(int p){
    if(cha(p)<0)return;
    sum(lc)=sum(rc)=cha(lc)=cha(rc)=cha(p);
    cha(p)=-1;
}
inline void update(int p,int l,int r,int k){
    if(l<=l(p)&&r>=r(p)){
        sum(p)=k,cha(p)=k;return;
    }pushdown(p);
    int mid=l(p)+r(p)>>1;
    if(l<=mid)update(lc,l,r,k);
    if(r>mid)update(rc,l,r,k);
    sum(p)=min(sum(lc),sum(rc));
}   
inline void modified(int u,int v,int k){
    int fu=top[u],fv=top[v];
    while(fu!=fv){
        if(dep[fu]>dep[fv])update(1,dfn[fu],dfn[u],k),u=fa[fu],fu=top[u];
        else update(1,dfn[fv],dfn[v],k),v=fa[fv],fv=top[v];
    }
    if(dfn[u]>dfn[v])swap(u,v);
    update(1,dfn[u],dfn[v],k);
}
inline int ask(int p,int l,int r){
    if(l<=l(p)&&r>=r(p))return sum(p);
    pushdown(p);
    int mid=l(p)+r(p)>>1;
    int ans=2147483647;
    if(l<=mid)ans=min(ans,ask(lc,l,r));
    if(r>mid)ans=min(ans,ask(rc,l,r));
    return ans; 
}
inline void query(int x){
    if(x==id){printf("%d\n",sum(1));return;}
    if(dfn[x]>dfn[id]&&dfn[x]<=qu[id]){printf("%d\n",ask(1,dfn[x],qu[x]));return;}
    if(dfn[id]<=qu[x]&&dfn[id]>dfn[x]){
        int u=id;
        int fx=top[x],fu=top[u],zc=u;
        while(fu!=fx){
            zc=u;u=fa[fu];fu=top[u];
        }
        if(u!=x)zc=son[x];
        printf("%d\n",min(ask(1,1,dfn[zc]-1),ask(1,qu[zc]+1,n)));return;
    }
    printf("%d\n",ask(1,dfn[x],qu[x]));
}
int main(){
    n=read(),m=read();
    for(int i=1,u,v;i<n;++i){
        u=read(),v=read();add(u,v),add(v,u);
    }tot=0;
    for(int i=1;i<=n;i++)w[i]=read();id=read();
    dep[id]=1,fa[id]=id; dfs1(id);dfs2(id,id); build(1,1,n);
    for(int i=1,opt;i<=m;++i){
        opt=read();
        if(opt==1)id=read();
        if(opt==2){
            int u=read(),v=read(),k=read();modified(u,v,k);
        }
        if(opt==3){
            int x=read();query(x);
        }
    }
}