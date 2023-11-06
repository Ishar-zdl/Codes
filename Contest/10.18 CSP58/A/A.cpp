/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-18 07:53:21 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-18 14:41:52
 */
#include<bits/stdc++.h>
#define int long long 
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
const int N=1e6+5;
int n,m,Q,a[N],num[15],tot;
bool f[(int)1e5+5][1100],able[(int)1e5+5];
unordered_map<int,bool>mp1;
unordered_map<int,int>mp2;
// unordered_map<pair<int,int>,int>mp;
#define lc p<<1
#define rc p<<1|1
struct question{
    int opt,l,r,x;
}qu[N];
struct Tree{
    int l,r,sum,add;
    #define l(p) t[p].l
    #define r(p) t[p].r
    #define sum(p) t[p].sum
    #define add(p) t[p].add
}t[N*4];
void build(int p,int l,int r){
    l(p)=l,r(p)=r;
    if(l==r){sum(p)=1<<a[l]-1;return;}
    int mid=l+r>>1;
    build(lc,l,mid),build(rc,mid+1,r);
    sum(p)=(sum(lc)|sum(rc));
    // cout<<sum(p)<<endl;
}
inline void pushdown(int p){
    if(!add(p))return;
    sum(lc)=sum(rc)=1<<add(p)-1;
    add(lc)=add(rc)=add(p);add(p)=0;
    return;
}
void modified(int p,int l,int r,int x){
    // cout<<x<<"XXXXXXXXXXX\n";
    if(l<=l(p)&&r>=r(p)){add(p)=x;sum(p)=(1<<(x-1));return;}
    pushdown(p);
    int mid=l(p)+r(p)>>1;
    if(l<=mid)modified(lc,l,r,x);
    if(r>mid)modified(rc,l,r,x);
    sum(p)=sum(lc)|sum(rc);
    // cout<<sum(p)<<"FDKJSL\n";
}
int query(int p,int l,int r){
    // cout<<l(p)<<' '<<r(p)<<' '<<sum(p)<<endl;
    if(l<=l(p)&&r>=r(p))
        return sum(p);
    pushdown(p);
    int mid=l(p)+r(p)>>1;
    int ans=0;
    if(l<=mid)
    ans|=query(lc,l,r);
    if(r>mid)
    ans|=query(rc,l,r);
    return ans;
}
inline void prepare(){
    able[0]=true;
    for(int i=0;i<(1<<tot);++i)f[0][i]=true;
    for(int i=0;i<m;++i){
        if(!able[i])continue;
        for(int s=0;s<(1<<tot);++s){
            if(!f[i][s])continue;
            for(int k=1;k<=tot;++k){
                f[i][s|(1<<k-1)]=true;
                if(i+num[k]<=m)f[i+num[k]][s|(1<<k-1)]=true,able[i+num[k]]=true;
            }
        }
    }
}
main(){
    // freopen("past5.in","r",stdin),freopen("past.out","w",stdout);
    n=read(),m=read(),Q=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        if(!mp1[a[i]])
        num[++tot]=a[i],mp1[a[i]]=true,mp2[a[i]]=tot;
        a[i]=mp2[a[i]];
    }
    build(1,1,n);
    // m=0;
    for(int i=1;i<=Q;++i){
        qu[i].opt=read(),qu[i].l=read(),qu[i].r=read(),qu[i].x=read();
        if(qu[i].opt==1){
            if(!mp2[qu[i].x]){mp2[qu[i].x]=++tot;num[tot]=qu[i].x;qu[i].x=tot;}
            else qu[i].x=mp2[qu[i].x];
        }
        // if(qu[i].opt==2)m=max(m,qu[i].x);
    }
    prepare();
    for(int i=1;i<=Q;++i){
        if(qu[i].opt==1)modified(1,qu[i].l,qu[i].r,qu[i].x);
        else{
            if(f[qu[i].x][query(1,qu[i].l,qu[i].r)])
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}