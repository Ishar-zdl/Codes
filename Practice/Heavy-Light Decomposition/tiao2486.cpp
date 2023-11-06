/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-04 15:48:52 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-05 15:31:14
 */
#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc (p<<1|1)
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
const int N=1e5+5;
int tl,tr;
int tll,tlr,trl,trr,ansr,ansl;
int n,m,tot,head[N],top[N],w[N],fa[N],son[N],siz[N],dep[N],dfn[N],rnk[N];
struct edge{
    int v,next;
}e[N*4];
struct segment_tree{
    int ls,rs,l,r,sum,cha;
    #define ls(p)  t[p].ls
    #define rs(p)  t[p].rs
    #define l(p)   t[p].l
    #define r(p)   t[p].r
    #define sum(p) t[p].sum
    #define cha(p) t[p].cha
}t[N*4];
void add(int u,int v){
    e[++tot]={v,head[u]};head[u]=tot;
}
void dfs1(int x){
    siz[x]=1;
    for(int i=head[x],y;i;i=e[i].next)
        if(!dep[y=e[i].v]){
            fa[y]=x;dep[y]=dep[x]+1,dfs1(y),siz[x]+=siz[y];
            if(!son[x]||siz[y]>siz[son[x]])son[x]=y;
        }
}
void dfs2(int x,int t){
    dfn[x]=++tot;rnk[tot]=x;top[x]=t;
    if(son[x])dfs2(son[x],t);
    for(int i=head[x],y;i;i=e[i].next){
        y=e[i].v;
        if(y!=fa[x]&&y!=son[x])dfs2(y,y);
    }
}
void build(int p,int l,int r){
    // cout<<l<<' '<<r<<' '<<p<<endl;
    l(p)=l,r(p)=r;
    if(l==r){rs(p)=ls(p)=w[rnk[l]],sum(p)=1;return;}
    int mid=l(p)+r(p)>>1;
    build(lc,l,mid),build(rc,mid+1,r);
    ls(p)=ls(lc),rs(p)=rs(rc),sum(p)=sum(lc)+sum(rc);
    if(rs(lc)==ls(rc))sum(p)--;
}
inline void pushdown(int p){
    if(!cha(p))return;
    ls(lc)=rs(lc)=ls(rc)=rs(rc)=cha(lc)=cha(rc)=cha(p);
    sum(lc)=sum(rc)=1;
    cha(p)=0;
}
inline void update(int p,int l,int r,int k){
    // cout<<1<<endl;
    // cout<<l<<' '<<r<<' '<<l(p)<<' '<<r(p)<<endl;
    if(l<=l(p)&&r>=r(p)){
        ls(p)=rs(p)=k;sum(p)=1,cha(p)=k;
        return;
    }pushdown(p);
    int mid=l(p)+r(p)>>1;
    if(l<=mid)update(lc,l,r,k);
    if(r>mid)update(rc,l,r,k);
    sum(p)=sum(lc)+sum(rc);
    if(rs(lc)==ls(rc))sum(p)--;
    
    ls(p)=ls(lc),rs(p)=rs(rc);
    // cout<<sum(p)<<' '<<ls(p)<<' '<<rs(p)<< endl;
}
inline void modified(int u,int v,int k){
    // 
    int fu=top[u],fv=top[v];
    while(fu!=fv){
        if(dep[fu]>dep[fv])update(1,dfn[fu],dfn[u],k),u=fa[fu],fu=top[u];
        else update(1,dfn[fv],dfn[v],k),v=fa[fv],fv=top[v];
    }
    if(dep[u]>dep[v])swap(u,v);
    update(1,dfn[u],dfn[v],k);
}
inline int ask(int p,int l,int r){
    // cout<<l<<' '<<r<<' '<<p<<' '<<l(p)<<' '<<r(p)<<endl;
    if(l<=l(p)&&r>=r(p)){
        if(tl==0){tl=ls(p);tr=rs(p);return sum(p);}
        if(ls(p)==tr){tr=rs(p);return sum(p)-1;}
        tr=rs(p);return sum(p);
    }
    pushdown(p);
    int mid=l(p)+r(p)>>1,ans=0;
    if(l<=mid)ans+=ask(p<<1,l,r);
    if(r>mid)ans+=ask(p<<1|1,l,r);
    return ans;
}
inline void query(int u,int v){
    // if(dfn[u]>dfn[v])swap(u,v);
    tl=tr=0;
    tll=tlr=trl=trr=ansl=ansr=0;
    int fu=top[u],fv=top[v],ans1=0,ans2=0;
    while(fu!=fv){
        if(dep[fu]>dep[fv]){
            // cout<<dfn[fu]<<' '<<dfn[u]<<' ';
            ans1+=ask(1,dfn[fu],dfn[u]),u=fa[fu],fu=top[u];
            if(ansr==tr)ans1--;
            ansr=tl;
            // cout<<endl<<"tr"<<tr<<endl;
            // cout<<ans1<<endl;
        }
        else{
            // cout<<dfn[fv]<<' '<<dfn[v]<<' ';
            ans2+=ask(1,dfn[fv],dfn[v]),v=fa[fv],fv=top[v];
            if(ansl==tr)ans2--;
            ansl=tl;
            // cout<<ans2<<endl;
        }
        tl=tr=0;
    }
    if(dfn[u]>dfn[v])swap(u,v),swap(ansr,ansl);
    // if(dep[u]>dep[v])swap(u,v);
    
    int ans=ans1+ans2+ask(1,dfn[u],dfn[v]);
    // cout<<dfn[u]<<' '<<dfn[v]<<' '<<tl<<' '<<tr<<' '<<ansr<< endl;
    if(tl==ansr)ans--;
    if(tr==ansl)ans--;
    write(ans);putchar('\n');
}
int main(){
    freopen("date.in","r",stdin);freopen("date.out","w",stdout);
    n=read(),m=read();fa[1]=dep[1]=1;
    for(int i=1;i<=n;i++)w[i]=read();
    for(int i=1,u,v;i<n;i++)
        u=read(),v=read(),add(u,v),add(v,u);
    dfs1(1);tot=0;dfs2(1,1);build(1,1,n);
    // for(int i=1;i<=n;i++)cout<<dfn[i]<<endl;
    for(int i=1,u,v,k;i<=m;i++){
        char s;cin>>s;
        // cin>>s;
        // scanf(" %c",&s);
        // char s=getchar();
        // while(s!='Q'&&s!='C')s=getchar();
        u=read(),v=read();
        if(s=='Q')query(u,v);
        if(s=='C') k=read(),modified(u,v,k);
    }
    return 0;
}