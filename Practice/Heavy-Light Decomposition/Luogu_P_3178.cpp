/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-04 11:40:35 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-05 16:44:54
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
const int N=1e5+10;
int n,m,tot,head[N],dfn[N],son[N],dep[N],fa[N],w[N],siz[N],rnk[N],top[N];
pair<int,int>qu[N];
struct edge{
    int v,next;
}e[N*2];
struct Skadi{
    int sum,l,r,add;
    #define sum(p) t[p].sum
    #define l(p)   t[p].l
    #define r(p)   t[p].r 
    #define add(p) t[p].add
}t[N*4];
void add_edge(int u,int v){e[++tot]={v,head[u]};head[u]=tot;}
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
    
    top[x]=t;dfn[x]=++tot;rnk[tot]=x;qu[x].first=tot;//cout<<tot<<' '<<x<<endl;
    if(!son[x]){qu[x].second=tot;return;}
    dfs2(son[x],t);
    for(int i=head[x],y;i;i=e[i].next){
        y=e[i].v;
        if(y!=fa[x]&&y!=son[x])dfs2(y,y);
    }qu[x].second=tot;
}
inline void build(int p,int l,int r){
    l(p)=l;r(p)=r;
    if(l==r){sum(p)=w[rnk[l]];return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);build(p<<1|1,mid+1,r);
    sum(p)=sum(p<<1)+sum(p<<1|1);
}
inline void pushdown(int p){
    if(add(p)){
        sum(p<<1)+=(r(p<<1)-l(p<<1)+1)*add(p);
        sum(p<<1|1)+=(r(p<<1|1)-l(p<<1|1)+1)*add(p);
        add(p<<1)+=add(p),add(p<<1|1)+=add(p);add(p)=0;
    }
}
inline void change(int p,int x,int k){
    if(l(p)==r(p)){sum(p)+=k;return;}
    pushdown(p);
    int mid=l(p)+r(p)>>1;
    if(x<=mid)change(p<<1,x,k);
    else change(p<<1|1,x,k);
    sum(p)=sum(p<<1)+sum(p<<1|1);
}
inline void update(int p,int l,int r,int k){
    if(l<=l(p)&&r>=r(p)){
        sum(p)+=(r(p)-l(p)+1)*k;
        add(p)+=k;return;
    }pushdown(p);
    int mid=l(p)+r(p)>>1;
    if(l<=mid)update(p<<1,l,r,k);
    if(r>mid)update(p<<1|1,l,r,k);
    sum(p)=sum(p<<1)+sum(p<<1|1);
}
inline int ask_sum(int p,int l,int r){
    int ans=0;
    // cout<<l<<' '<<r<<' '<<p<<' '<<l(p)<<' '<<r(p)<< endl;
    if(l<=l(p)&&r>=r(p))return sum(p);
    pushdown(p);
    int mid=l(p)+r(p)>>1;
    if(l<=mid)ans+=ask_sum(p<<1,l,r);
    if(r>mid)ans+=ask_sum(p<<1|1,l,r);
    return ans;
}
inline void query(int x){
    int ans=0;int t=top[x];
    // cout<<t<<endl<<fa[t]<<endl<<dfn[x];
    while(t!=1)
        // cout<<t<<endl;
        ans+=ask_sum(1,dfn[t],dfn[x]),x=fa[t],t=top[x];
    write(ans+ask_sum(1,1,dfn[x])),putchar('\n');
}
main(){
    n=read(),m=read();dep[1]=fa[1]=1;
    for(int i=1;i<=n;i++)w[i]=read();
    for(int i=1,u,v;i<n;i++)
        u=read(),v=read(),add_edge(v,u),add_edge(u,v);
    dfs1(1);tot=0;dfs2(1,1);build(1,1,n);
    for(int i=1,pd,x,k;i<=m;i++){
        pd=read(),x=read();
        if(pd==1)k=read(),change(1,dfn[x],k);
        if(pd==2)k=read(),update(1,dfn[x],qu[x].second,k);
        if(pd==3)query(x);
    }
}