/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-24 08:19:39 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-28 18:57:33
 */
#include<bits/stdc++.h>
#define fo(n) for(int i=1;i<=n;i++)
#define N (int)5e5+5
using namespace std;
int n,m,s,d[N],dist[N],f[N][22],lg[N];
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
vector<int> node[N];
void dfs(int x,int y){
    f[x][0]=y;d[x]=d[y]+1;
    fo(__lg(d[x]))f[x][i]=f[f[x][i-1]][i-1];
    for(int i:node[x]) if(i!=y) dfs(i,x);
}
inline void lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y])x=f[x][__lg(d[x]-d[y])];
    if(x==y){write(x),putchar('\n');return;}
    for(int k=__lg(d[x]);k>=0;--k)
        if(f[x][k]!=f[y][k])x=f[x][k],y=f[y][k];
    write(f[x][0]);putchar('\n');return;
}
int vis[N];
int main(){
    int a,b;
    int t=read();
    while(t--){
    n=read();int s;
    fo(n-1)a=read(),b=read(),node[a].push_back(b),vis[b]=1;
    fo(n)if(!vis[i]){s=i;break;}
    dfs(s,0);
    a=read(),b=read(),lca(a,b);
    fo(n)d[i]=0,node[i].clear(),vis[i]=0;
    }
    return 0;
}