/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-23 11:10:43 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-24 21:28:22
 */
#include<bits/stdc++.h>
#define N (int)(1e5+5)
using namespace std;
int n,q,a[N],dfs[N],w[N],d[N],f[21][N],tot;vector<int> node[N];
pair<int,int> qu[N];
struct Skadi{
    int l,r,d;
    #define l(p) t[p].l
    #define r(p) t[p].r
    #define d(p) t[p].d
}t[N*4];
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
void build(int p,int l,int r){
    l(p)=l,r(p)=r;
    if(l==r){d(p)=a[l];return;}
    int mid=(l+r)>>1;
    build(p*2,l,mid);build(p*2+1,mid+1,r);
    d(p)=min(d(p*2),d(p*2+1));
}
inline void modify(int p,int x,int v){
    if(l(p)==r(p)){d(p)=v;return;}
    int mid=l(p)+r(p)>>1;
    if(x<=mid)modify(p*2,x,v);
    else modify(p*2+1,x,v);
    d(p)=min(d(p*2),d(p*2+1));
}
inline int query(int p,int l,int r){
    if(l>r)return (1<<30);
    if(l<=l(p)&&r>=r(p))return d(p);
    int mid=l(p)+r(p)>>1;
    int val=(1<<30);
    if(l<=mid)val=min(val,query(p*2,l,r));
    if(r>mid)val=min(val,query(p*2+1,l,r));
    return val; //max(d(p*2+1),d(p*2));
}
void dfss(int x,int fa){
    f[0][x]=fa;d[x]=d[fa]+1;
    for(int i=1;i<=__lg(d[x]);i++)f[i][x]=f[i-1][f[i-1][x]];
    tot++;qu[x].first=tot;a[tot]=w[x];dfs[x]=tot;
    for(int i:node[x]){
        if(i!=fa)dfss(i,x);
    }qu[x].second=tot;
}
int main(){
    n=read();q=read();int s;
    for(int i=1;i<=n;i++){
        int fa=read();w[i]=read();
        if(fa)node[fa].push_back(i),node[i].push_back(fa);
        else s=i;
    }dfss(s,0);
    build(1,1,n);
    for(int i=1;i<=q;i++){
        char a[10];scanf("%s",a);char pd=a[0];
        int x=read();
        if(pd=='V'){int v=read();modify(1,dfs[x],v);}
        if(pd=='E') s=x;
        if(pd=='Q'){
            // x=dfs[x];int y=s;s=dfs[s];
            int y=s;
            if(x==s){printf("%d\n",d(1));continue;}
            if(dfs[s]>=qu[x].first&&dfs[s]<=qu[x].second){
                // s=y;
                int de=d[s]-d[x]-1;
                for(int i=0;i<=20;i++)if(de&(1<<i))s=f[i][s];
                printf("%d\n",min(query(1,1,qu[s].first-1),query(1,qu[s].second+1,n)));s=y;continue;
            }
            printf("%d\n",query(1,qu[x].first,qu[x].second));
        }
    }
}