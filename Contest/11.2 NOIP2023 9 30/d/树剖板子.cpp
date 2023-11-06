/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-04 07:15:52 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-02 11:22:50
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
const int N=3e4+5;
int n,m,dfn[N],rnk[N],dep[N],head[N],w[N],tot,siz[N],son[N],top[N],fa[N];
struct edge{
    int v,next;
}e[N*2];
void add(int u,int v){e[++tot]={v,head[u]};head[u]=tot;}
void dfs1(int x){
    siz[x]=1;
    for(int i=head[x],y;i;i=e[i].next)
        if(!dep[y=e[i].v]){
            dep[y]=dep[x]+1;fa[y]=x;dfs1(y);siz[x]+=siz[y];
            if(!son[x]||siz[y]>siz[son[x]])son[x]=y;
        }
}
void dfs2(int x,int t){
    top[x]=t;dfn[x]=++tot;rnk[tot]=x;
    if(!son[x])return;
    dfs2(son[x],t);
    for(int i=head[x],y;i;i=e[i].next){
        y=e[i].v;
        if(y!=fa[x]&&y!=son[x])dfs2(y,y);
    }
}
struct tree{
    int sum,maxx,l,r;
    #define sum(p) t[p].sum
    #define maxx(p) t[p].maxx
    #define l(p) t[p].l
    #define r(p) t[p].r
}t[N*4];
void build(int p,int l,int r){
    l(p)=l,r(p)=r;
    if(l==r){sum(p)=maxx(p)=w[rnk[l]];return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);build(p<<1|1,mid+1,r);
    sum(p)=sum(p<<1)+sum(p<<1|1);maxx(p)=max(maxx(p<<1),maxx(p<<1|1));
}
inline int ask_sum(int p,int l,int r){
    int ans=0;
    if(l(p)>=l&&r(p)<=r)return sum(p);
    int mid=l(p)+r(p)>>1;
    if(l<=mid)ans+=ask_sum(p<<1,l,r);
    if(r>mid)ans+=ask_sum(p<<1|1,l,r);
    return ans;
}
inline int ask_max(int p,int l,int r){
    int ans=-1e5;
    if(l(p)>=l&&r(p)<=r)return maxx(p);
    int mid=l(p)+r(p)>>1;
    if(l<=mid)ans=max(ans,ask_max(p<<1,l,r));
    if(r>mid)ans=max(ans,ask_max(p<<1|1,l,r));
    return ans;
}
inline void query_sum(int u,int v){
    int ans=0,fu=top[u],fv=top[v];
    while(fu!=fv){
        if(dep[fu]>dep[fv])
            ans+=ask_sum(1,dfn[fu],dfn[u]),u=fa[fu];
        else
            ans+=ask_sum(1,dfn[fv],dfn[v]),v=fa[fv];
        fu=top[u],fv=top[v];
    }
    if(dfn[u]>dfn[v])swap(u,v);
    write(ans+ask_sum(1,dfn[u],dfn[v]));putchar('\n');
}
inline void query_max(int u,int v){
    int ans=-1e5,fu=top[u],fv=top[v];
    while(fu!=fv){
        if(dep[fu]>dep[fv])
            ans=max(ans,ask_max(1,dfn[fu],dfn[u])),u=fa[fu];
        else
            ans=max(ans,ask_max(1,dfn[fv],dfn[v])),v=fa[fv];
        fu=top[u],fv=top[v];
    }
    if(dfn[u]>dfn[v])swap(u,v);
    write(max(ans,ask_max(1,dfn[u],dfn[v])));putchar('\n');
}
inline void change(int p,int x,int k){
    if(l(p)==r(p)){sum(p)=maxx(p)=k;return;}
    int mid=l(p)+r(p)>>1;
    if(x<=mid)change(p<<1,x,k);
    else change(p<<1|1,x,k);
    sum(p)=sum(p<<1)+sum(p<<1|1);
    maxx(p)=max(maxx(p<<1),maxx(p<<1|1));
}
int main(){
    n=read();dep[1]=1;fa[1]=1;
    for(int i=1,u,v;i<n;i++)
        u=read(),v=read(),add(u,v),add(v,u);
    for(int i=1;i<=n;i++)w[i]=read();
    dfs1(1);tot=0;dfs2(1,1);
    build(1,1,n);
    m=read();
    for(int i=1,u,v;i<=m;i++){
        char s[11];
        scanf("%s",s);u=read(),v=read();
        if(s[1]=='M')query_max(u,v);
        if(s[1]=='S')query_sum(u,v);
        if(s[1]=='H')change(1,dfn[u],v);
    }
    return 0;
}