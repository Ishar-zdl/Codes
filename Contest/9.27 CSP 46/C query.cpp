/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-27 09:15:50 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-27 19:04:53
 */
#include<bits/stdc++.h>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
gp_hash_table<int,int> t1,t2;
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
int n,m,tot,d[N],f[N][20],head[N],ans[N];
struct Node{
    int cl,pd,x,num;
};
vector<Node>node[N];
struct edge{
    int v,next;
}e[N*2];
inline void add(int u,int v){
    e[++tot]={v,head[u]},head[u]=tot;
}
void dfs(int x,int fa){
    d[x]=d[fa]+1;f[x][0]=fa;
    int k=d[x]?__lg(d[x]):0;
    for(int i=1;i<=k;i++)f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x],y;i;i=e[i].next)
        if((y=e[i].v)!=fa)dfs(y,x);
}
inline int lca(int a,int b){
    if(d[a]<d[b])swap(a,b);
    while(d[a]>d[b])a=f[a][__lg(d[a]-d[b])];
    if(a==b)return b;
    for(int i=__lg(d[a]);i>=0;--i)
        if(f[a][i]!=f[b][i])a=f[a][i],b=f[b][i];
    return f[a][0];
}
void work(int w,int fa){
    t1[w+d[w]]++;t2[w-d[w]]++;
    // cout<<w<<endl;
    for(auto i:node[w]){
        // cout<<i.num<<' '<<i.cl<<' '<<i.x<<' '<<i.pd<<endl;
        int num=i.num,x=i.x,pd=i.pd;
        if(i.cl==1){
            ans[num]+=pd*t1[x];
        }else ans[num]+=pd*t2[x];
    }
    // cout<<endl;
    for(int i=head[w],y;i;i=e[i].next)
        if((y=e[i].v)!=fa)work(y,w);
    t1[w+d[w]]--;t2[w-d[w]]--;
}
int main(){
    freopen("query.in","r",stdin);freopen("query.out","w",stdout);
    n=read(),m=read();d[0]=-1;
    for(int i=1,a,b;i<n;i++){
        a=read(),b=read();add(a,b),add(b,a);
    }dfs(1,0);
    for(int i=1,a,b;i<=m;i++){
        a=read(),b=read();int L=lca(a,b);
        node[a].push_back({1,1,d[a],i});
        node[b].push_back({2,1,d[a]-2*d[L],i});
        node[L].push_back({2,-1,d[a]-2*d[L],i});
        L=f[L][0];
        node[L].push_back({1,-1,d[a],i});
    }
    work(1,0);
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}